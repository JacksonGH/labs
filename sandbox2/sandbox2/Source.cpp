#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <cstdio>
#include <sstream>//преобращование в строку
#include <cstring>//exp
using namespace std;



int main()
{
	char str[256];
	double num;
	do {
		gets_s(str);
		num = atof(str);
		std::ostringstream sstream;
		sstream << num;
		std::string varAsString = sstream.str();
		cout << str << "\n" << varAsString << "\n";
		if (str == varAsString) { cout << "You are genius\n"; break; }
		else cout << "idiot\n";
	} while (1);//не работает для +8 и 8.0
	system("pause");
}