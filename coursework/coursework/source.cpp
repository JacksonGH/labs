#define _CRT_SECURE_NO_WARNINGS
#include "modules.h"

int main()
{
	//add workers 
	/*if (workersFixture() == 0) cout << "Succeesss";
	system("pause");*/

	//auth
	/*int choice;
	User *user = new User;
	while (auth(choice, user));

	if (choice == EXIT_OPTION)
		return 0;*/

	//test
	User *user = new User;
	user->access = false;
	user->role = 1;
	strcpy(user->login, "TestUser");
	hash <string> hash;
	user->pass = hash("TestPass" + SALT);

	//new module(user)
	while (mainApp(user));

	return 0;
}