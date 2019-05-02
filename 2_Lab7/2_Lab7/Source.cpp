#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <ctime>
#include <math.h> 

using namespace std;

double readDoubleNum();
double fun(double);
double methodAuto2(double, double, double, double);
double methodAvg(double, double, double);
double methodTrap(double, double, double);

int main()
{
	double a, b, e, n;
	cout << "Enter interval [a; b]:\n";
	a = readDoubleNum();
	b = readDoubleNum();
	if (a > b) {
		swap(a, b);
	}
	cout << "Enter e(initial approximation):\n";
	e = readDoubleNum();
	cout << "Enter step n:\n";
	n = readDoubleNum();

	double res = methodAuto2(n, b, a, e);
	cout << "Result is " << res << '\n';

	system("pause");
}
double methodAuto2(double n, double b, double a, double e) {
	double f1, f2;
	do {
		f1 = methodAvg(n, b, a);
		f2 = methodTrap(n, b, a);
		n *= 2;
	} while (fabs(f1 - f2) >= e);
	return (f2 + 2 * f1) / 3;
}
double methodAvg(double n, double b, double a) {
	double sum = 0, h = (b - a) / n;
	for (double i = a; i < b; i += h) {
		sum += fun(i);
	}
	return h * sum;
}
double methodTrap(double n, double b, double a) {
	double sum = 0, h = (b - a) / n;
	for (double i = a + h; i < b; i += h) {
		sum += fun(i);
	}
	return h * ((fun(a) + fun(b)) / 2 + sum);
}
double fun(double x) {
	return pow(x, 3) - 5 * pow(x, 2);
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