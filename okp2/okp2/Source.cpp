#include "arr.h"
using namespace std;

int main() {
	int size;
	cout << "Input size of array\n";
	size = acceptCorrectINum();

	int *arr = new int[size];

	/*fillArrRand(arr, size);
	coutArr(arr, size);

	swapmaxminel(arr, size);
	coutarr(arr,size);*/

	cout << "Input elem of arr\n";
	for (int i=0;i<size;i++) {
		cin >> arr[i];
	}
	//delEvenElem(arr, size);
	delElemMult5(arr,size);
	coutArr(arr, size);
	
	/*shiftArr(arr, size);
	coutArr(arr, size);

	sortIArr(arr, size);
	coutArr(arr, size);*/

	delete[] arr;

	system("pause");
	return 0;
}