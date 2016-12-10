#include <Raytracer/Raytracer.h>
#include <Windowing/DisplayWindow.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <sys/time.h>
#endif

using namespace Windowing;

#ifdef _WIN32
const TCHAR *DisplayWindow::className = TEXT("DisplayWindowClass");
#endif

DisplayWindow::DisplayWindow(int width, int height)
{
	image = NULL;

#ifdef _WIN32
	WNDCLASS wc = {
		0, WndProc, 0, 0, GetModuleHandle(NULL), NULL, LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1), NULL, className
	};

	RegisterClass(&wc);

	RECT windowRect = { 0, 0, width, height };
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

	handle = CreateWindow(className, TEXT("DisplayWindow"), WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top, NULL, NULL, GetModuleHandle(NULL), this);
#else
	display = XOpenDisplay(NULL);
	if (display != NULL)
	{
		window = XCreateSimpleWindow(display, RootWindow(display, 0), 0, 0, width, height, 1, 0,
			0);
		XStoreName(display, window, "DisplayWindow");
		
		XSelectInput(display, window, ExposureMask);
		
		Atom wmDelete = XInternAtom(display, "WM_DELETE_WINDOW", True);
		XSetWMProtocols(display, window, &wmDelete, 1);
		
		XMapWindow(display, window);
		XFlush(display);
	}
#endif
};

DisplayWindow::~DisplayWindow()
{
#ifdef _WIN32
	if (handle != NULL)
		DestroyWindow(handle);
#endif
}

#ifdef _WIN32
LRESULT DisplayWindow::WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		SetWindowLongPtr(handle, GWLP_USERDATA,
			(LONG_PTR)((CREATESTRUCT *)lParam)->lpCreateParams);
		break;

	case WM_CLOSE:
		DestroyWindow(handle);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		{
			PAINTSTRUCT paintStruct;
			BeginPaint(handle, &paintStruct);

			DisplayWindow *window = (DisplayWindow *)GetWindowLongPtr(handle, GWLP_USERDATA);
			if (window->image != NULL)
			{
				BITMAPINFO bitmapInfo;
				ZeroMemory(&bitmapInfo, sizeof(bitmapInfo));
				
				int width = window->image->GetWidth();
				int height = window->image->GetHeight();

				int stride = (width * 3 + 3) / 4 * 4;

				bitmapInfo.bmiHeader.biBitCount = 24;
				bitmapInfo.bmiHeader.biHeight = height;
				bitmapInfo.bmiHeader.biPlanes = 1;
				bitmapInfo.bmiHeader.biSize = sizeof(bitmapInfo.bmiHeader);
				bitmapInfo.bmiHeader.biWidth = width;

				BYTE *bits;
				HBITMAP bitmap = CreateDIBSection(paintStruct.hdc, &bitmapInfo, DIB_RGB_COLORS,
					(void **)&bits, NULL, 0);
				if (bitmap != NULL)
				{
					for (int y = height - 1; y >= 0; y--)
					{
						BYTE *ptr = bits;
						for (int x = 0; x < width; x++)
						{
							window->image->GetBGRPixel(x, y, 2.2f, ptr);
							ptr += 3;
						}

						bits += stride;
					}

					HDC bitmapDC = CreateCompatibleDC(paintStruct.hdc);
					SelectObject(bitmapDC, bitmap);
					BitBlt(paintStruct.hdc, 0, 0, width, height, bitmapDC, 0, 0, SRCCOPY);
					DeleteDC(bitmapDC);
					DeleteObject(bitmap);
				}
			}

			EndPaint(handle, &paintStruct);
			return 0;
		}
	}

	return DefWindowProc(handle, message, wParam, lParam);
}
#else
void DisplayWindow::HandleEvent(XEvent &event)
{
	switch (event.type)
	{
		case Expose:
		{
			if (image == NULL)
				break;
			
			int width = image->GetWidth();
			int height = image->GetHeight();
			
			int stride = (width * 3 + 3) / 4 * 4;
			stride = width * 4;
			
			unsigned char *buffer = (unsigned char *)malloc(width * height * 4);
			if (buffer == NULL)
				break;
			
			unsigned char *bits = buffer;
			for (int y = 0; y < height; y++)
			{
				unsigned char *ptr = bits;
				for (int x = 0; x < width; x++)
				{
					image->GetBGRPixel(x, y, 2.2f, ptr);
					ptr += 4;
				}

				bits += stride;
			}
			
			XImage *image = XCreateImage(display, DefaultVisual(display, 0), 24, ZPixmap, 0,
				(char *)buffer, width, height, 32, 0);
			if (image != NULL)
			{
				XPutImage(display, window, DefaultGC(display, 0), image, 0, 0, 0, 0, width, height);
				XDestroyImage(image);
			}
			else
				free(buffer);
			
			break;
		}
	}
}
#endif

float DisplayWindow::GetTime()
{
#ifdef _WIN32
	static DWORD firstTick = GetTickCount();
	return (GetTickCount() - firstTick) / 1000.0f;
#else
	static time_t startSec = 0;
	timeval t;
	gettimeofday(&t, NULL);
	
	if (startSec == 0)
		startSec = t.tv_sec;

	return ((t.tv_sec - startSec) + (t.tv_usec / 1000) / 1000.0f);
#endif
}

bool DisplayWindow::ProcessMessages()
{
#ifdef _WIN32
	if (handle == NULL)
		return false;

	MSG message;
	while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);

		if (message.message == WM_QUIT)
		{
			handle = NULL;
			return false;
		}
	}

	return true;
#else
	if (display == NULL)
		return false;

	while (XPending(display) > 0)
	{
		XEvent event;
		XNextEvent(display, &event);
		HandleEvent(event);

		if (event.type == ClientMessage)
		{
			display = NULL;
			return false;
		}
	}

	return true;
#endif
}

void DisplayWindow::SetImage(Raytracer::Image *image)
{
	this->image = image;
}

void DisplayWindow::Update()
{
#ifdef _WIN32
	InvalidateRect(handle, NULL, FALSE);
#else
	XEvent event;
	event.type = Expose;
	XSendEvent(display, window, True, ExposureMask, &event);
#endif
}
