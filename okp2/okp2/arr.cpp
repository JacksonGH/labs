#include "arr.h"

using namespace std;

int acceptCorrectINum() {
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
double acceptCorrectDNum() {
	while (1) {
		double num;
		cin >> num;
		if (cin.get() == '\n') {
			cout << " Permissible value.\n";
			return num;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << " Error 1: Value should be type double.\n";
		}
	}
}
void coutArr(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<" ";
	}
	cout << "\n\n";
	return;
}
void coutArr(double *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n\n";
	return;
}
void fillArrRand(int *arr, int size) {
	srand(time(NULL));
	int a, b;
	cout << "Input [a;b]\n";
	a = acceptCorrectINum();
	b = acceptCorrectINum();
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (b - a + 1) + a;
	}
	return;
}
void sortIArr(int *arr, int size) {
	int count = 0, i = 0;
	while (i + 1 < size) {
		if (arr[i] < arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
			if (i > 0) {
				i--;
			}
			else {
				i = ++count;
			}
		}
		else {
			i = ++count;
		}
	}
}
void delEvenElem(int *arr, int &size) {
	int count = 1, size1 = size;
	for (int i = 0; i + 1 < size; i++) {
		if (!(arr[i] % 2) || (count > 1)) {//оптимизировать counter>1 рассматривает не все
			while (i + count < size) {
				if (!(arr[i + count] % 2)) {
					count++;
					size1--;
				}
				else break;
			}
			if (i + count < size) swap(arr[i], arr[i + count]);
			else {
				size1--;
				break;
			}
		}
	}
	size = size1;
}
void delElemMult5(int *arr, int &size) {
	int count = 1, size1 = size;
	for (int i = 0; i + 1 < size; i++) {
		if (!(arr[i] % 5) || (count > 1)) {//оптимизировать counter>1 рассматривает не все
			while (i + count < size) {
				if (!(arr[i + count] % 5)) {
					count++;
					size1--;
				}
				else break;
			}
			if (i + count < size) swap(arr[i], arr[i + count]);
			else {
				size1--;
				break;
			}
		}
	}
	size = size1;
}
void shiftArr(int *arr, int size) {
	int shift;
	cout << "Input shift\n";
	cin >> shift;
	for (int i = 0; i < shift; i++) {
		for (int j = 0; j + 1 < size; j++) {
			swap(arr[j], arr[j + 1]);
		}
	}
}
void swapMaxMinEl(int *arr, int size) {
	int i_max = 0, i_min = 0;
	for (int i = 1; i < size; i++) {
		if (arr[i] > arr[i_max]) i_max = i;
		else if (arr[i] < arr[i_min]) i_min = i;
	}
	cout << "Max is " << arr[i_max] << ".Min is " << arr[i_min] << ".\n";
	swap(arr[i_max], arr[i_min]);
}