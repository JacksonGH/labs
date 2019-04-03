//#include <stdio.h>
//#include <stdlib.h>//rand
#include <iostream>
#include <algorithm>
#include <conio.h>
#include <ctime>
//#include <cstdlib>

using namespace std;

struct foo
{
	char ch;
	short id;
	short opt;
	int value;
};

int main()
{
	//int i = 0;
	////char s, s1, s2;
	//while (1) {
	//	int c=_getch();

	//	cout << "if you want to continue, press any key. if you want to exit the program, press esc." << ++i << "\n";
	//	if (c == 27) break;
	//	_getch();
	//}
	cout << sizeof(foo) << "\n";
	system("pause");

	return 0;
}
//int main() {
//	int arr[6] = { 4, 5, 6, 2, 8, 5 }, arr_i[6];
//	int i_max = 0, j = 0;
//
//	for (int i = 1; i < 6; i++) {
//		if (arr[i] > arr[i_max]) {
//			i_max = i;
//			arr_i[j] = i_max;
//		}
//	}
//	cout << arr[arr_i[j]] << "\n";
//
//	system("pause");
//	return 0;
//}