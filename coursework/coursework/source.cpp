#include <iostream>
#include <conio.h>
#include "entry.h"

using namespace std;

int main()
{
	cout << "";
	char *pass = new char[100];
	int i = 0;
	char t;
	for (i = 0;;) {
		t = _getch();
		if (t >= 'a' && t <= 'z' || t >= 'A' && t <= 'Z' || t >= '0' && t <= '9') {
			pass[i++] = t;
			cout << "*";
		}
		if (t == '\b' &&  i >= 1) {
			cout << "\b \b";
			i--;
		}
		if (t == '\r') {
			pass[i] = '\0';
			break;
		}
	}
	system("pause");


	User *users = new User[MAX_ARRAY_SIZE];
	int num = 0;
	readAllUsers(users, num);
	coutUsers(users, num);
	system("pause");

	int choice;
	while (entry(choice));

	if (choice == REGISTER) {
		system("pause");
		return 0;
	}

	system("pause");
	return 0;
}