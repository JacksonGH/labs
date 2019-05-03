#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <math.h> 

using namespace std;

double fun(double);
double diff_fun(double);
double diff_diff_fun(double);
double newthonMethod(double i, double e);
double readDoubleNum();
int readIntNum();

int main()
{
	double a, b, e;
	cout << "Enter interval [a; b]:\n";
	a = readIntNum();
	b = readIntNum();
	if (a > b)
		swap(a, b);
	cout << "Enter e(initial approximation):\n";
	e = readDoubleNum();

	double *arr = new double[6];
	int size = 0;

	for (int i = a; i <= b; i += 1)
	{

		if (fun(i) * fun(i + 1) < 0)
			arr[size++] = newthonMethod(i, e);
		else if (fun(i) == 0)
			arr[size++] = i;
	}
	
	for (int i = 0; i < size; i++)
		cout << i + 1 << " root is " << arr[i] << "\n";

	system("pause");
}
double newthonMethod(double x, double e) {
	double h;
	do {
		h = fun(x) / diff_fun(x);
		x -= h;
	} while (fabs(h) > e);
	return x;
}
double fun(double x) {
	return pow(x, 3) - 5 * pow(x, 2) + 12;
}
double diff_fun(double x) {
	return 3 * pow(x, 2) - 10 * x;
}
double diff_diff_fun(double x) {
	return 6 * x - 10;
}
double readDoubleNum() {
	while (1) {
		double num;
		cin >> num;
		if (cin.get() == '\n') {
			return num;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << " Error 1: Value should be type double.\n ";
		}
	}
}
int readIntNum() {
	while (1) {
		int num;
		cin >> num;
		if (cin.get() == '\n') {
			return num;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << " Error 1: Value should be type int.\n ";
		}
	}
}