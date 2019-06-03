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
			cout << "Error 1: Value should be type int.\n";
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
			cout << "Error 1: Value should be type double.\n";
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
			cout << "Number should be positive\n";
		}
	};
	return num;
}
double readPosDoubleNum() {
	double num;
	while (1) {
		num = readDoubleNum();
		if (num >= 0) {
			return num;
		}
		else {
			cout << "Number should be positive\n";
		}
	};
	return num;
}
void doPauseAndCls() {
	_getch();  _getch();
	system("cls");
}
bool confirmDelete() {
	cout << "Do you want to delete(options: yes/no)?\n";

	string confirm;
	do {
		getline(cin, confirm);
	} while (confirm != YES && confirm != NO);

	return confirm == YES;
}
bool checkCan(int yourRole, int changedUaerRole) {
	return yourRole > changedUaerRole;
}