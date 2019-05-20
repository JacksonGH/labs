#define _CRT_SECURE_NO_WARNINGS
#include "modules.h"

int main()
{
	//cout users
	/*User *users = new User[MAX_ARRAY_SIZE];
	int num;
	readAllUsers(users, num);
	coutUsers(users, num);*/

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
	user->role = 0;
	strcpy(user->login, "TestUser");
	hash <string> hash;
	user->pass = hash("TestPass" + SALT);

	//new module(user)
	while(mainApp(user));

	_getch(); _getch();
	return 0;
}