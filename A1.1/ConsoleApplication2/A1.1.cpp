// Assignment 1.1 - Circle Calculation
// By David Kirk & Marcel Weber

#define PI 3.1415
#include <iostream>
#include <limits>
using namespace std;

int main() {
	cout << "Circle Calculation:" << endl;
	cout << "Enter radius: ";
	double r = 0.0;

	// Input
	while (!(cin >> r) || r <= 0.0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Use 123.567 format and only positive, non-zero numbers." << endl;
		cout << "Enter radius: ";
	}

	// Output
	cout << " Area =          " << PI * r * r << endl;
	cout <<	" Circumference = " << 2 * PI * r << endl;

	// Pause
	cout << "Press ENTER to exit";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (cin.get() != '\n') {
		;
	}
	return 0;
}

