#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;

const int SIZE = 81;

char *readStr();
char *dynStr(char *);
double readIntNum();

void calcSum(int **, int);
int selectFillMode(int **, int);
void fillArr(int **, int, int, int);
void fillArr(int **, int);
void coutArr(int **, int);

int endOrRepeat();

int main() {
	srand(time(NULL));

	int size;
	do {
		do {
			cout << "Choose length of array\n";
			size = readIntNum();
		} while (size <= 0);

		int **arr = new int*[size];
		for (int i = 0; i < size; i++) {
			arr[i] = new int[size];
		}
		/*while (1) {
			cout << "Select array fill mode(enter \"rand\" or \"own\")\n";
			char *fillMode = readStr();

			if (!strcmp(fillMode, "rand")) {
				int a, b;
				do {
					cout << "Enter a range of values[a;b]\n";
					a = readIntNum();
					b = readIntNum();
				} while (a > b);
				fillArr(arr,size,a,b);
				break;
			}
			else if (!strcmp(fillMode, "own")) {
				fillArr(arr, size);
				break;
			}
			else	cout << "Error 2: Invalid value of string variable.\n";
		}*/
		while (selectFillMode(arr, size));
		coutArr(arr, size);

		calcSum(arr, size);
		for (int i = 0; i < size; ++i)
			delete[] arr[i];
		delete[] arr;
		/*for (int i = 0; i < size; i++) {
			if (arr[i][0] < 0) {
				cout << "Number str is " << i + 1;
				int sumBefore = 0, sumAfter = 0;
				for (int j = 0; j < i; j++) sumAfter += arr[i][j];
				if (i) cout << ". SumAfter is " << sumAfter;
				for (int j = i + 1; j < size; j++) sumBefore += arr[i][j];
				if (i + 1 != size) cout << ". SumBefore is " << sumBefore;
				cout << '\n';
			}
		}*/
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
	int len = strlen(str);
	char *dynStr = new char[len + 1];
	strcpy_s(dynStr, len + 1, str);
	return dynStr;
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
void calcSum(int **arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i][0] < 0) {
			cout << "Number str is " << i + 1;
			int sumBefore = 0, sumAfter = 0;
			for (int j = 0; j < i; j++) sumAfter += arr[i][j];
			if (i) cout << ". SumAfter is " << sumAfter;
			for (int j = i + 1; j < size; j++) sumBefore += arr[i][j];
			if (i + 1 != size) cout << ". SumBefore is " << sumBefore;
			cout << '\n';
		}
	}
}
int selectFillMode(int **arr, int size) {
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
void fillArr(int **arr, int n, int a, int b) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % (b - a + 1) + a;
		}
	}
	//return 0;
}
void fillArr(int **arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Enter element " << i + 1 << " string\n";
		for (int j = 0; j < n; j++) {
			cout << "\t" << j + 1 << " column: ";
			arr[i][j] = readIntNum();
		}
	}
	//return 0;
}
void coutArr(int **arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << " " << arr[i][j] << "\t";
		}
		cout << "\n";
	}
}
int endOrRepeat() {
	cout << "If you want to continue, press any key. If you want to exit the program, press ESC.\n";
	if (_getch() == 27) return 0;
	_getch();
	return 1;
}
//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//#include <string>
//using namespace std;
//double acceptCorrectINum();
//void coutArr(int **arr, int size);
//int main() {
//	srand(time(NULL));
//
//	int size;
//	do {
//		cout << " Choose length of array\n ";
//		size = acceptCorrectINum();
//	} while (size <= 0);
//
//	string fillMode;
//	int **arr = new int*[size];
//	for (int i = 0; i < size; i++) {
//		arr[i] = new int[size];
//	}
//	while (1) {
//		cout << " Select array fill mode(enter \"rand\" or \"own\")\n -random\n -own\n ";
//		getline(cin, fillMode);
//		if (fillMode == "rand") {
//			int a = -50, b = 50;
//			for (int i = 0; i < size; i++) {
//				for (int j = 0; j < size; j++) {
//					arr[i][j] = rand() % (b - a + 1) + a;
//				}
//			}
//			break;
//		}
//		else if (fillMode == "own") {
//			for (int i = 0; i < size; i++) {
//				cout << " Enter element " << i + 1 << " string\n";
//				for (int j = 0; j < size; j++) {
//					cout << "\t" << j + 1 << " column: ";
//					arr[i][j] = acceptCorrectINum();
//				}
//			}
//			break;
//		}
//		else	cout << " Error 2: Invalid value of string variable.\n ";
//	}
//
//	coutArr(arr, size);
//
//	for (int i = 0; i < size; i++) {
//		if (arr[i][0] < 0) {
//			cout << " Number str is " << i + 1;
//			int sumBefore = 0, sumAfter = 0;
//			for (int j = 0; j < i; j++) sumAfter += arr[i][j];
//			if (i) cout << ". SumAfter is " << sumAfter;
//			for (int j = i + 1; j < size; j++) sumBefore += arr[i][j];
//			if (i + 1 != size) cout << ". SumBefore is " << sumBefore << "\n";
//		}
//	}
//
//	system("pause");
//	return 0;
//}
//double acceptCorrectINum() {
//	while (1) {
//		int num;
//		cin >> num;
//		if (cin.get() == '\n') {
//			return num;
//		}
//		else {
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			cout << " Error 1: Value should be type int.\n ";
//		}
//	}
//}
//void coutArr(int **arr, int size) {
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			cout << " " << arr[i][j] << "\t";
//		}
//		cout << "\n";
//	}
//}