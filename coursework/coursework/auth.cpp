#include "auth.h"

int authentication(int &choice, User *user) {
	while (1) {
		cout << "Choose what you want:\n"
			" 1.login\n"
			" 2.register\n"
			" 0.exit\n";
		choice = readIntNum();
		system("cls");

		switch (choice)
		{
		case LOGIN:
			return loginUser(user);
		case REGISTER:
			return registerUser(user);
		case EXIT_OPTION:
			return EXIT_OPTION;
		}
	}
}
int loginUser(User *user) {
	getLoginAndPass(user);

	int num;
	User *users = new User[MAX_ARRAY_SIZE];
	if (readAllUsers(users, num)) {
		cout << "File with users doesn't exist.\n";
		doPauseAndCls();
		return 1;
	}

	for (int i = 0; i < num; i++) {
		if (users[i].login != user->login) continue;

		if (users[i].pass == user->pass) {
			if (users[i].access == NOT_AVAILABLE) {
				cout << ACCESS_DENIED;
				doPauseAndCls();
				return 1;
			}

			cout << "Login successful.\n";
			user->role = users[i].role;
			user->access = users[i].access;
			doPauseAndCls();
			return 0;
		}
		
		cout << "Wrong password.\n";
		doPauseAndCls();
		return 1;
	}

	cout << "Unknown login.\n";
	doPauseAndCls();
	return 1;
}
int addUser(User *user) {
	getLoginAndPass(user);

	int num;
	User *users = new User[MAX_ARRAY_SIZE];
	readAllUsers(users, num);

	for (int i = 0; i < num; i++) {
		if (users[i].login == user->login) {
			cout << "Login already taken.\n";
			doPauseAndCls();
			return 1;
		}
	}

	insertUser(user);
	return 0;
}
int registerUser(User *user) {
	if (addUser(user) != 1) {
		return 1;
	}
	cout << "Successful registration.\n";
	doPauseAndCls();

	cout << ACCESS_DENIED;
	doPauseAndCls();

	return 0;
}
void getLoginAndPass(User *user) {
	cout << "Enter login:\n";
	do {
		getline(cin, user->login);
	} while (!isValidLogin(user->login));

	char t, *pass = new char[MAX_STR_SIZE];
	string strPass;
	cout << "Enter password:\n";
	do {
		for (int i = 0;;) {
			t = _getch();
			if (t >= 'a' && t <= 'z' || t >= 'A' && t <= 'Z' || t >= '0' && t <= '9' || t == '_') {
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
		cout << '\n';
		strPass = pass;
	} while (!isValidPass(strPass));
	hash <string> hash;
	user->pass = hash(strPass + SALT);
}
void coutUsers(User *users, int num) {
	cout << left << setw(20) << "Login"
		<< setw(10) << "Role"
		<< setw(10) << "Access"
		<< '\n';
	cout << setfill('-') << setw(40) << "" << setfill(' ') << '\n';

	for (int i = 0; i < num; i++) {
		cout << setw(20) << users[i].login;
		cout << setw(10) << ((users[i].role == ROLE_ADMIN)
			? "admin"
			: "user");
		cout << setw(10) << ((users[i].access == AVAILABLE)
			? "   \/"
			: "   X");
		cout << '\n';
	}
}
void insertUser(User *user) {
	ofstream fadd(USERS, ios::binary | ios::app);
	fadd.write((char*) user, sizeof *user);
	fadd.close();
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
bool isValidLogin(string str) {
	cmatch result;
	regex regular("^[a-zA-Z][a-zA-Z0-9-_\.]{1,19}$");
	bool valid = std::regex_match(str.c_str(), result, regular);
	if (!valid)
		cout << "Login must be a string(2-20 characters long), which can contain letters or numbers, the first character must be a letter.\n";
	return valid;
}
bool isValidPass(string str) {
	cmatch result;
	regex regular("(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])[0-9a-zA-Z_]{6,20}");
	bool valid = std::regex_match(str.c_str(), result, regular);
	if (!valid)
		cout << "Password must be a string, 6-20 characters long, which can contain letters, numbers or an underscore(! must contain at least uppercase letter, lowercase letter and number).\n";
	return valid;
}