#include <iostream>
#include <algorithm>
#include <conio.h>
#include <ctime>

using namespace std;

const int SIZE = 81;

char *readStr();
char *dynStr(char *);
int readIntNum();

int selectFillMode(int *, int);
void fillArr(int*, int, int, int);
void fillArr(int*, int);
//int fillArr(int*, int, int, int);
//int fillArr(int*, int);
void coutArr(int*, int);
int max(int*, int);

int endOrRepeat();

int main()
{
	srand(time(NULL));
	int size;

	do {
		do {
			cout << "Enter the number of elements in the array: ";
			size = readIntNum();
		} while (size < 1);
		int* arr = new int[size];

		while (selectFillMode(arr, size));
		coutArr(arr, size);
		cout << "Max element is " << max(arr, size) << "\n";

		//реализация через функцию
		int *sort_arr = new int[size];
		for (int i = 0; i < size; i++) {
			sort_arr[i] = arr[i];
		}
		double lenArr = size;
		do {
			for (int i = 1, j = 0; i < lenArr; i += 2, j++) {
				sort_arr[j] = max(*(sort_arr + i - 1), *(sort_arr + i));
				if (i + 2 == lenArr)
					sort_arr[j + 1] = *(sort_arr + i + 1);
			}
			lenArr = ceil(lenArr / 2.);
		} while (lenArr > 1);
		cout << *sort_arr << '\n';

		delete[] arr;
	} while (endOrRepeat());

	return 0;
}
char *readStr() {
	char str[SIZE];
	cin >> str;
	while (cin.get() != '\n');
	return dynStr(str);
}
char *dynStr(char *str) {
	int len = 0;
	for (; str[len] != '\0'; len++);
	char *dynStr = new char[len + 1];
	strcpy_s(dynStr, len + 1, str);
	return dynStr;
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
			cout << "Error 1: Value should be type int.\n";
		}
	}
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
void fillArr(int *arr, int n, int a, int b) {
	for (int i = 0; i < n; i++)
		*(arr + i) = rand() % (b - a + 1) + a;
	//return 0;
}
void fillArr(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i << " element of array: ";
		cin >> *(arr + i);
	}
	//return 0;
}
void coutArr(int *arr, int size) {
	cout << "Array: ";
	for (int i = 0; i < size; i++)
		cout << *(arr + i) << ' ';
	cout << '\n';
}
int max(int* a, int size)//проверка значение на n<
{
	if (size == 2) return max(*a, *(a + 1));
	else if (size == 1) return *a;

	int leftHalf, rightHalf;
	leftHalf = max(a, size / 2);
	rightHalf = (size % 2) ? max(a + size / 2, size / 2 + 1) : max(a + size / 2, size / 2);
	return max(leftHalf, rightHalf);
}
int endOrRepeat() {
	cout << "If you want to continue, press any key. If you want to exit the program, press ESC.\n";
	if (_getch() == 27) return 0;
	_getch();
	return 1;
}