#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>

using namespace std;

const int SIZE = 81;

//char *readStr();
//char* dynStr(char *str);
int strLen(char *);
char* putStr2MidStr1(char*, char*);
int endOrRepeat();

int main() {
	do {
		char str1[SIZE], str2[SIZE];
		puts("Enter the first line:");
		gets_s(str1);
		puts("Enter the second line:");
		gets_s(str2);
		/*char *str1, *str2;
		puts("Enter the first line:");
		str1 = readStr();
		puts("Enter the second line:");
		str2 = readStr();*/

		//вставка 2 строки в середину первой
		putStr2MidStr1(str1, str2);
		printf("The first line has become - %s.\n", str1);
		/*puts("If you want to continue, press any key. If you want to exit the program, press ESC.");
		if (_getch() == 27) break;
		_getch();*/
	} while (endOrRepeat());//завершение программы по нажатию ESC

	return 0;
}
//char *readStr() {
//	char str[SIZE];
//	gets_s(str);
//	return dynStr(str);
//}
//char* dynStr(char *str) {
//	int len = strLen(str);
//	char *dynStr = new char[len + 1];
//	strcpy_s(dynStr, len + 1, str);
//	return dynStr;
//}
int strLen(char *str) {
	int i = 0;
	do {
		++i;
	} while (str[i] != '\0');
	return i;
}
char* putStr2MidStr1(char* str1, char* str2) {
	int lenStr2 = strLen(str2), lenStr1 = strLen(str1), count = lenStr1 / 2;
	for (int i = 0; i + count <= lenStr1; i++) {
		str2[i + lenStr2] = str1[i + count];
	}
	str1[count] = '\0';
	strcat(str1, str2);
	return str1;
}
//char* putStr2MidStr1(char* str1, char* str2) {
//	int count = strlen(str1) / 2, lenStr2 = strlen(str2);
//	//for (int i = 0; i + count < strlen(str1) + strlen(str2); i++) {
//	for (int i = 0; i <= lenStr2; i++) {
//		swap(str1[i + count], str2[i]);
//	}
//	count = strlen(str1);
//	for (int i = 0; i <= strlen(str2); i++) {
//		str1[i + count] = str2[i];
//	}
//	return str1;
//}
int endOrRepeat() {
	cout << "If you want to continue, press any key. If you want to exit the program, press ESC.\n";
	if (_getch() == 27) return 0;
	_getch();
	return 1;
}