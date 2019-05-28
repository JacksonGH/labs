#include "work_with_users.h"

void viewAllUsers() {
	User *users = new User[MAX_ARRAY_SIZE];
	int num = 0;
	readAllUsers(users, num);
	coutUsers(users, num);
}
bool readAllUsers(User *users, int &num) {
	ifstream fin(USERS, ios::binary | ios::in);

	int m = 0;
	if (!fin.is_open()) {
		return 1;
	}
	else {
		while (!fin.eof()) {
			fin.read((char*)&users[m], sizeof users[m]);
			m++;
		}
		fin.close();
		m--;
	}
	num = m;

	return 0;
}
void coutUsers(User *users, int num) {
	cout << left << setw(20) << "Login"
		<< setw(10) << "Role"
		<< setw(10) << "Access"
		<< '\n';
	cout << setfill('-') << setw(40) << "" << setfill(' ') << '\n';

	for (int i = 0; i < num; i++) {
		cout << setw(20) << users[i].login
			<< setw(10) << (
			(users[i].role == ROLE_ADMIN_VALUE) ? ROLE_ADMIN_NAME : ROLE_USER_NAME
			)
			<< setw(10) << (
			(users[i].access == AVAILABLE) ? HAS_ACCESS : HAS_NOT_ACCESS
			)
			 << '\n';
	}
}
void coutUser(User user) {
	cout << setw(20) << left << user.login
		<< setw(10) << (
		(user.role == ROLE_ADMIN_VALUE) ? ROLE_ADMIN_NAME : ROLE_USER_NAME
		)
		<< setw(10) << (
		(user.access == AVAILABLE) ? HAS_ACCESS : HAS_NOT_ACCESS
		)
	<< '\n' << setfill('-') << setw(80) << "" << setfill(' ') << '\n';
}
int addUser(int access) {
	User *user = new User;
	getCredentials(user);

	if (access == ROLE_SUPER_ADMIN_VALUE) {
		string role;
		cout << "Enter user role(available options: user or admin).\n";

		do {
			getline(cin, role);
		} while (role != ROLE_ADMIN_NAME && role != ROLE_USER_NAME);

		user->role = (role == ROLE_ADMIN_NAME)
			? ROLE_ADMIN_VALUE
			: ROLE_USER_VALUE;
	}
	else {
		user->role = ROLE_USER_VALUE;
	}

	user->access = AVAILABLE;

	insertUser(user);
	cout << "Successful added new " << (user->role == ROLE_ADMIN_VALUE ? ROLE_ADMIN_NAME : ROLE_USER_NAME) << ".\n";

	return 0;
}
void searchUsers(User *users, int num, int choice) {
	bool flag = false;

	switch (choice) {
	case 1:
	{
		char login[MAX_STR_SIZE];
		cout << "Enter login:\n";
		cin.getline(login, sizeof login);

		for (int i = 0; i < num; i++) {
			if (!strcmp(users[i].login, login)) {
				coutUser(users[i]);
				flag = true;
				break;
			}
		}

		if (!flag) {
			cout << "Not found\n";
		}

		break;
	}
	case 2:
	{
		int access;
		cout << "Enter access(available options: 1(has access) or 0(no access)).\n";

		do {
			access = readPosIntNum();
		} while (access != AVAILABLE && access != NOT_AVAILABLE);

		for (int i = 0; i < num; i++) {
			if (access == users[i].access) {
				coutUser(users[i]);
				flag = true;
			}
		}

		if (!flag) {
			cout << "Not found\n";
		}

		break;
	}
	case 3: {
		string option;
		cout << "Enter user role(available options: user or admin).\n";

		do {
			getline(cin, option);
		} while (option != ROLE_ADMIN_NAME && option != ROLE_USER_NAME);

		int role = (option == ROLE_ADMIN_NAME ? 1 : 0);
		for (int i = 0; i < num; i++) {
			if (role == users[i].role) {
				coutUser(users[i]);
				flag = true;
			}
		}

		if (!flag) {
			cout << "Not found\n";
		}

		break;
	}
	}
}
void sortUsers(User *users, int num, int choice) {
	int sortFrom;
	do {
		cout << "Enter from sort:\n"
			" 1.[1-9][a-z]\n"
			" 2.[9-1][z-a]\n"
			" 0.back\n";
		sortFrom = readIntNum();
	} while (sortFrom < 0 || sortFrom > 2);

	bool flag;
	switch (choice) {
	case 1:
	{
		if (sortFrom == 1) {
			do {
				flag = false;
				for (int i = 0; i < num - 1; i++) {
					if (strcmp(users[i].login, users[i + 1].login) > 0) {
						swap(users[i], users[i + 1]);
						flag = true;
					}
				}
			} while (flag);
		}
		else {
			do {
				flag = false;
				for (int i = 0; i < num - 1; i++) {
					if (strcmp(users[i].login, users[i + 1].login) < 0) {
						swap(users[i], users[i + 1]);
						flag = true;
					}
				}
			} while (flag);
		}

		break;
	}
	case 2:
	{
		if (sortFrom == 1) {
			do {
				flag = false;
				for (int i = 0; i < num - 1; i++) {
					if (getAccessNameFromValue(users[i].access) > getAccessNameFromValue(users[i + 1].access)) {
						swap(users[i], users[i + 1]);
						flag = true;
					}
				}
			} while (flag);
		}
		else {
			do {
				flag = false;
				for (int i = 0; i < num - 1; i++) {
					if (getAccessNameFromValue(users[i].access) < getAccessNameFromValue(users[i + 1].access)) {
						swap(users[i], users[i + 1]);
						flag = true;
					}
				}
			} while (flag);
		}

		break;
	}
	case 3: {
		if (sortFrom == 1) {
			do {
				flag = false;
				for (int i = 0; i < num - 1; i++) {
					if (getRoleNameFromValue(users[i].role) > getRoleNameFromValue(users[i + 1].role)) {
						swap(users[i], users[i + 1]);
						flag = true;
					}
				}
			} while (flag);
		}
		else {
			do {
				flag = false;
				for (int i = 0; i < num - 1; i++) {
					if (getRoleNameFromValue(users[i].role) < getRoleNameFromValue(users[i + 1].role)) {
						swap(users[i], users[i + 1]);
						flag = true;
					}
				}
			} while (flag);
		}

		break;
	}
	}

	coutUsers(users, num);
}
string getAccessNameFromValue(int access) {
	return access == AVAILABLE ? HAS_ACCESS : HAS_NOT_ACCESS;
}
string getRoleNameFromValue(int role) {
	switch (role) {
	case ROLE_USER_VALUE:
		return ROLE_USER_NAME;
	case ROLE_ADMIN_VALUE:
		return ROLE_ADMIN_NAME;
	case ROLE_SUPER_ADMIN_VALUE:
		return ROLE_SUPER_ADMIN_NAME;
	default:
		throw new exception("Unknown option.\n");
	}
}