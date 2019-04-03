#include<iostream>
using namespace std;

void main() {

	int arr[]{ 2,4,5,7,-7,2,8,99,1,2,5 };
	int min = arr[0];
	for (int j = 0; j < sizeof(arr) / sizeof(arr[0]); j++) {
		min = (min < arr[j]) ? min : arr[j];
	}

	cout << min << endl;
	system("pause");
}