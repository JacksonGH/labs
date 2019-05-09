#include "common.h"

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
			cout << "Error 1: Value should be type int.\n ";
		}
	}
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
			cout << "Error 1: Value should be type double.\n ";
		}
	}
}
int readPosIntNum() {
	int num;
	while(1) {
		num = readIntNum();
		if (num >= 0) {
			return num;
		}
		else {
			cout << "Number should be positive";
		}
	};
	return num;
}
double readPosDoubleNum() {
	double num;
	while (1) {
		num = readIntNum();
		if (num >= 0) {
			return num;
		}
		else {
			cout << "Number should be positive";
		}
	};
	return num;
}
void doPauseAndCls() {
	system("pause");
	system("cls");
}