// A2.1.cpp
// Weber / Kirk

#include <iostream>

//Excercise 1a)
//#define SQUARE(a) a*a
//Excercise 1b)
//We don't get correct results for g because the term of a = 1-x isn't evaluated before SQUARE(a) is evaluated. It just replaces
//a by 1-x, so it evaluates 1-x*1-x = 1-2*x.
//We don't get correct results for h either because it replaces 1/SQUARE(a) by 1/a*a and first evaluates 1/a and then multiplies it by a.
//Excercise 1b)
//After our observations we made the following adjustments. First we need to evaluate the term a so we put a in parentheses. To evaluate a*a at first we also 
//put this one in parentheses. Which concluded to the following #define

#define SQUARE(a) ((a)*(a))

using namespace std;

int function_f(int x)
{
	return SQUARE(x);
}

int function_g(int x)
{
	return SQUARE(1 - x);
}

float function_h(float x)
{
	return (1 / SQUARE(x));
}

int main()
{
	float f_values[10] = {};
	float g_values[10] = {};
	float h_values[10] = {};

	for (int i = 0; i < 10; i++)
	{
		f_values[i] = function_f(i + 1);
		g_values[i] = function_g(i + 1);
		h_values[i] = function_h((float)(i + 1));
	}

	cout << "f" << "\t" << "g" << "\t" << "h" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << f_values[i] << "\t" << g_values[i] << "\t" << h_values[i] << endl;
	}

	cout << "To exit press ENTER";
	cin.get();


	return 0;
}

