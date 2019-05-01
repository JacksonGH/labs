#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <ctime>
#include <math.h> 

using namespace std;

double fun(double);
double diff_fun(double);
char *newthonMethod(double i, double e);
double readDoubleNum();
int readIntNum();

int main()
{
	cout << "Enter interval [a; b]:\n";
	int a = readIntNum();
	int b = readIntNum();
	cout << "e(initial approximation):\n";
	double e = readDoubleNum();

	double *arr = new double[6];
	int j = 0;
	char *res = new char[30];
	for (int i = a; i <= b; i += 2)
	{
		if (strcmp((res = newthonMethod(i, e)), "-")) {
			arr[j++] = atof(res);
		}
	}
	
	cout << arr[0] << '\n';
	cout << arr[1] << '\n';
	cout << arr[2] << '\n';

	system("pause");
}
char *newthonMethod(double x, double e) {
	double h;
	int i = 0;
	char *st = new char[10];
	do {
		h = fun(x) / diff_fun(x);
		if (fabs(h) <= e)
			return _gcvt(x, 10, st);
		x -= h;
	} while (++i < 10);
	strcpy(st, "-");
	return st;
}
double fun(double x) {
	return pow(x, 3) - 5 * pow(x, 2) + 12;
}
double diff_fun(double x) {
	return 3 * pow(x, 2) - 10 * x;
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