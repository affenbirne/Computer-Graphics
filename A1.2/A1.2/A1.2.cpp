// A1.2.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

// optional precision parameter
#define PRECI 8
#define W (PRECI + 4)

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << setw(W+7) << "f100" << setw(W) << "f101" << setw(W) << "f102" << setw(W) << "f103" << setw(W) << "f104" << endl;

	// Iterate through a = 2.0, 2.1, ..., 3.9
	for (float a = 2.0f; a < 3.999f; a += 0.1f) {
		cout << "a = " << fixed << setprecision(1) <<  a;
		double f = 0.5;		// f0

		// Iterate 100 times
		for (int i = 0; i < 100; i++) {
			f = a * f * (1 - f);
		}
		cout << fixed << setprecision(PRECI) << setw(W) << f;
		f = a * f * (1 - f);
		cout << setw(W) << f;
		f = a * f * (1 - f);
		cout << setw(W) << f;
		f = a * f * (1 - f);
		cout << setw(W) << f;
		f = a * f * (1 - f);
		cout << setw(W) << f << endl;
		//cout << " -----------------------------------------------------------------" << endl;
	}

	// Pause
	cout << "Press ENTER to exit";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (cin.get() != '\n') {
		;
	}
    return 0;
}

