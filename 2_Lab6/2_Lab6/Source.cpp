#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

int main() {
	srand(time(NULL));

	int stop = 0;
	do {
		cout <<
			"Instruction:\n"
			" 5 to exit\n"
			"Enter: "
			;
		int choice = readIntNum();
		switch (choice) {
		case 5:
			stop = 1;
			break;
		}
		system("cls");
	} while (!stop);

	return 0;
}
double readIntNum() {
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