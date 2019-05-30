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
	user->access = true;
	user->role = ROLE_SUPER_ADMIN_VALUE;
	strcpy(user->login, "MAIN_ADMIN");
	hash <string> hash;
	user->pass = hash("admin" + SALT);

	/*bool a = find(begin(AVAILABLE_ROLES), end(AVAILABLE_ROLES), "user");

	bool b = end(AVAILABLE_ROLES);

	bool d = find(begin(AVAILABLE_ROLES), end(AVAILABLE_ROLES), "user") != end(AVAILABLE_ROLES);

	int c = 1;*/

	//new module
	//addUser(user->role);

	//modules
	while (mainApp(user));

	return 0;
}