#include "entry.h"

int entry(int &choice, User *user) {
	while (1) {
		cout << "Choose what you want:\n"
			" 1.login\n"
			" 2.register\n";
		choice = readIntNum();
		system("cls");

		if (choice == LOGIN)
			return loginUser(user);
		if (choice == REGISTER)
			return registerUser(user);
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
int registerUser(User *user) {
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
	cout << "Successful registration.\n";
	doPauseAndCls();

	cout << "You get access to the resource as soon as the administrator confirms your account\n";

	return 0;
}
void getLoginAndPass(User *user) {
	cout << "Enter login:\n";
	do {
		getline(cin, user->login);
	} while (!isValidLogin(user->login));

	cout << "Enter password:\n";
	do {
		getline(cin, user->pass);
	} while (!isValidPass(user->pass));
}
void coutUsers(User *users, int num) {
	for (int i = 0; i < num; i++) {
		cout << users[i].login << " "
			<< users[i].pass << " "
			<< users[i].role << " "
			<< users[i].access << "\n";
	}
}
void insertUser(User *user) {
	ofstream fadd(USERS, ios::binary | ios::app);
	//fadd.write((char*) &user, sizeof user);
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
	regex regular("^[a-zA-Z][a-zA-Z0-9-_\.]{1,18}$");
	bool valid = std::regex_match(str.c_str(), result, regular);
	if (!valid)
		cout << "Login must be a string(2-20 characters long), which can contain letters or numbers, the first character must be a letter.\n";
	return valid;
}
bool isValidPass(string str) {
	cmatch result;
	regex regular("^[a-zA-Z0-9-_\.]{6,18}$");
	bool valid = std::regex_match(str.c_str(), result, regular);
	if (!valid)
		cout << "Password must be a string, 6-20 characters long, which can contain letters, numbers or an underscore.\n";
	return valid;
}