#ifndef DISPLAY_DISPLAYWINDOW_H
#define DISPLAY_DISPLAYWINDOW_H

#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#else
#include <X11/Xlib.h>
#endif

namespace Raytracer
{
	class Image;
}

namespace Windowing
{
	/**
	 * Opens a window that can be used to display an image.
	 */
	class DisplayWindow
	{
	private:
#ifdef _WIN32
		static const TCHAR *className;
		HWND handle;

		static LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);
#else
		Display *display;
		Window window;
		
		void HandleEvent(XEvent &event);
#endif

		Raytracer::Image *image;

	public:
		/**
		 * Constructs a new DisplayWindow object and opens the window on the screen.
		 *
		 * @param width The width of the window
		 * @param height The height of the window
		 */
		DisplayWindow(int width, int height);

		/**
		 * Destructs a DisplayWindow.
		 */
		~DisplayWindow();

		/**
		 * Retrieves current execution time.
		 *
		 * @return The time, in seconds, since the first call to GetTime().
		 */
		float GetTime();

		/**
		 * Handles any pending window messages.
		 *
		 * @return true if the window is still open, false if it has been closed
		 */
		bool ProcessMessages();

		/**
		 * Specifies the image to be drawn in the window.
		 *
		 * @param image The image to be drawn
		 */
		void SetImage(Raytracer::Image *image);

		/**
		 * Refreshes the window by redrawing the associated image.
		 */
		void Update();
	};
}

#endif // DISPLAY_DISPLAYWINDOW_H
