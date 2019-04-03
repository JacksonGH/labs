#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

/*
double giveAndCheckDNum(double num) {
	cin >> num;
	//return cin.get() == '\n';
	if (cin.get() == '\n') {
		return num;
	}
	else {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return 0;
	}
}

int giveAndCheckINum(int num) {
	cin >> num;
	//return cin.get() == '\n';
	if (cin.get() == '\n') {
		return num;
		}
	else {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return 0;
	}
}
*/
double readDoubleNum();
double fY_x(double x);
double fS_x(double x);
int endOrRepeat();


int main() {
	setlocale(LC_ALL, "rus");

	double a, b, h;
	
	while (1) {
		cout << "Введите диапазон значений [a,b] , шаг h и n:\n";
		a = readDoubleNum();
		b = readDoubleNum();
		h = readDoubleNum();
		if (b>a && (b-a)>=h) break;
		else cout << "Неверное значение" << endl;
	}
	/*
	double y_x;
	cout << "Таблица значений\n  x" << "\t Y(x)" << "\t\t S(x)" << "\t\t|Y(x)_S(x)|" << endl;
	//printf("%s","Таблица значений\n  x\t Y(x)\t Y(x)\t\t | Y(x)_S(x) | \n");
	for (double x = a; b >= x; x += h) {
		//printf(" \%.1lf", x);
		cout << " " << x;
		y_x = (exp(x) + exp(-x)) / 2;
		cout << "\t" << y_x;
		//printf("\t%lf", y_x);
		int fact = 2;
		double s_x = 1;
		for (int k = 1; k <= n; k++) {
			if (k != 1) fact *= 2 * k*(2 * k - 1);
			s_x += pow(x, 2 * k) / fact;
		}
		cout << "\t\t" << s_x;
		//printf("\t%lf", s_x);
		cout << "\t\t" << fabs(y_x - s_x) << "\n";
		//printf("\t%lf\n", fabs(y_x - s_x));
	}*/

	double y_x,s_x;
	cout << "Таблица значений\n  x" << "\t Y(x)" << "\t\t S(x)\t\tSteps" << "\t\t|Y(x)_S(x)|" << endl;
	for (double x = a; b >= x; x += h) {
		cout << " " << x;
		y_x = fY_x(x);
		cout << "\t" << y_x;
		s_x = fS_x(x);
		cout << "\t\t" << fabs(y_x - s_x) << "\n";
	}

	system("pause");
	return 0;
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
			cout << "Error 1: Value should be type int.\n";
		}
	}
}
double fY_x(double x) {
	return (exp(x) + exp(-x)) / 2;
}
double fS_x(double x) {
	int fact = 2;
	double s_x = 1;
	for (int k = 1;; k++) {
		if (k != 1) fact *= 2 * k*(2 * k - 1);
		s_x += pow(x, 2 * k) / fact;
		//if (fabs(fY_x(x) - s_x) >= 0.001) {
		if (fabs(fY_x(x) - s_x) <= 0.001) {
			cout << "\t\t" << s_x;
			cout << "\t\t" << k;
			break;
		}
		else if (k >= 16) {
			cout << "\t\t" << s_x;
			cout << "\t\terror";
			break;
		}
	}
	return s_x;
}
int endOrRepeat() {
	cout << "If you want to continue, press any key. If you want to exit the program, press ESC.\n";
	if (_getch() == 27) return 0;
	_getch();
	return 1;
}