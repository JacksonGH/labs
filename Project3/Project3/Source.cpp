#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {//������� �-��� ��� �������� ������������ ��������
			//��� ������� n-�� ������� �������
	//srand(time(NULL));
	/*static
	const int SIZE = 30;
	int arr[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		arr[i] = i + 1;
		//cout << (arr[i] = rand() % 50 + 1) << " ";
	}
	//cout << "\n";

	for (int i = 2, count = 1; (i + count) < SIZE; count++) {
		arr[i] = arr[i + count];
		arr[i + 1] = arr[i + count + 1];
		i += 2;
	}

	for (int i = 0; i < (SIZE - SIZE / 3); ++i) {
		cout << arr[i] << " ";
	}
	*/


	int size;
	cin >> size;
	int *arr = new int [size];
	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
		//cout << (arr[i] = rand() % 50 + 1) << " ";
	}
	//cout << "\n";

	for (int i = 2, count = 1; (i + count) < size; count++) {
		arr[i] = arr[i + count];
		arr[i + 1] = arr[i + count + 1];
		i += 2;
	}

	for (int i = 0; i < (size - size / 3); ++i) {
		cout << arr[i] << " ";
	}
	delete[] arr;//������� ��

	system("pause");
	return 0;
}