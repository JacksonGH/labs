#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <conio.h>

using namespace std;

const int SIZE = 81;

int readIntNum();
char *readStr();
char *dynStr(char*);
int selectFillMode(int*, int);

void delEvery3rdElem(int *, int &);
void fillArr(int *, int, int, int);
void fillArr(int *, int);
void coutArr(int *, int);

int endOrRepeat();

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int size;

	do {
		do {
			cout << "Enter the number of elements in the array: ";
			size = readIntNum();
		} while (size < 1);
		int *arr = new int[size];

		while (selectFillMode(arr, size));
		/*string fillMode;
		while (1) {
			cout << "Select array fill mode(enter \"rand\" or \"own\" to fill array): ";
			getline(cin, fillMode);
			if (fillMode == "rand") {
				int a, b;
				do {
					cout << "Enter a range of values[a;b]\n";
					a = readIntNum();
					b = readIntNum();
				} while (a > b);
				fillArr(arr, size, a, b);
				break;
			}
			else if (fillMode == "own") {
				fillArr(arr, size);
				break;
			}
			else cout << "Error 2: Invalid value of string variable.\n ";
		}*/

		cout << "Array before delete:";
		coutArr(arr, size);

		delEvery3rdElem(arr, size);

		cout << "Array after delete:";
		coutArr(arr, size);

		delete[] arr;
	} while (endOrRepeat());

	return 0;
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
			cout << "Error 1: Value should be type int.\n ";
		}
	}
}
char *readStr() {
	char str[SIZE];
	cin >> str;
	while (cin.get() != '\n');
	return dynStr(str);
}
char *dynStr(char *str) {
	int len = strlen(str);
	char *dynStr = new char[len + 1];
	strcpy_s(dynStr, len + 1, str);
	return dynStr;
}
int selectFillMode(int *arr, int size) {
	/*char choice[SIZE];
	cout << "Select array fill method(enter \"rand\" or \"own\"): ";
	cin >> choice;
	while (cin.get() != '\n');*/
	cout << "Select array fill method(enter \"rand\" or \"own\"): ";
	char *choice = readStr();

	if (!strcmp(choice, "rand")) {
		int a, b;
		do {
			cout << "Enter a range of values[a;b]\n";
			a = readIntNum();
			b = readIntNum();
		} while (a > b);
		fillArr(arr, size, a, b);
		return 0;
		//if (!fillArr(arr, size, a, b)) return 0;
		//return 1;
	}
	else if (!strcmp(choice, "own")) {
		fillArr(arr, size);
		return 0;
		//if (!fillArr(arr, size)) return 0;
		//return 1;
	}
	else cout << "You should write \"rand\" or \"own\"\n";
	return 1;
}
void delEvery3rdElem(int *arr, int &size) {
	for (int i = 2, count = 1; i + count < size; count++, i += 2) {
		arr[i] = arr[i + count];
		arr[i + 1] = arr[i + 1 + count];
	}
	size -= size / 3;
}
void fillArr(int *arr, int n, int a, int b) {
	for (int i = 0; i < n; i++)
		*(arr + i) = rand() % (b - a + 1) + a;
}
void fillArr(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i << " element of array: ";
		cin >> *(arr + i);
	}
}
void coutArr(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << " " << arr[i];
	}
	cout << "\n";
	return;
}
int endOrRepeat() {
	cout << "If you want to continue, press any key. If you want to exit the program, press ESC.\n";
	if (_getch() == 27) return 0;
	_getch();
	return 1;
}