#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void coutIArr(int *arr, int size);
void fillArrRandVal(int *arr, int size, int a, int b);
void sortIArr(int *arr, int size);
void delEvenElem(int *arr, int &size);

int main() {
	int a, b, size;
	cout << "enter size of array\n";
	cin >> size;
	cout << "enter a of [a;b]\n";
	cin >> a;
	cout << "enter b of [a;b]\n";
	cin >> b;
	int *arr = new int[size];

	fillArrRandVal(arr, size, a, b);//task 2
	coutIArr(arr, size);
	
	sortIArr(arr, size);//task 3
	coutIArr(arr, size);
	
	delEvenElem(arr, size);//task4
	coutIArr(arr, size);

	delete[] arr;
	cout << "\n";

	system("pause");
	return 0;
}
void fillArrRandVal(int *arr,int size,int a,int b) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (b - a + 1) + a;
	}
}
void coutIArr(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
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
void delEvenElem(int *arr,int &size) {
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