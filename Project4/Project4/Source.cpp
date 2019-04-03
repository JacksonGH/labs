#include  <iostream>
#include  <ctime>
#include  <stdlib.h>
#include "farr.h"
using namespace std;

int main() {
	int size = 10;
	int *arr = new int[size];
	fillArrRand(arr, size, 0, 10);
	coutArr(arr, size);
	delete[] arr;
	system("pause");
	return 0;
}