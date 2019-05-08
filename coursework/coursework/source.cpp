#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

const int LOGIN = 1;
const int REGISTER = 2;

const int ROLE_ADMIN = 1;
const int ROLE_USER = 0;

const int AVAILABLE = 1;
const int NOT_AVAILABLE = 0;

const string USERS = "D://users.txt";
const int MAX_ARRAY_SIZE = 100;

struct User
{
	string login;
	string pass;
	bool role;
	bool access;
};

int loginUser();
int registerUser();
int enter(int&);

User getLoginAndPass();

bool readAllUsers(User *, int &);
void insertUser(User);

void coutUsers(User *, int);

bool isValidLogin(string);
bool isValidPass(string);
int readIntNum();

void doPauseAndCls();

int main()
{
	User *users = new User[MAX_ARRAY_SIZE];
	int num = 0;
	readAllUsers(users, num);
	coutUsers(users, num);
	system("pause");

	int choice;
	while (enter(choice));

	if (choice == REGISTER)
		return 0;

	system("pause");
	return 0;
}
int enter(int &choice) {
	while(1) {
		cout << "Choose what you want:\n"
			" 1.login\n"
			" 2.register\n";
		choice = readIntNum();
		system("cls");

		if (choice == LOGIN)
			return loginUser();
		if (choice == REGISTER)
			return registerUser();
	}
}
int loginUser() {
	User user = getLoginAndPass();
	user.role = ROLE_USER;
	user.access = NOT_AVAILABLE;

	int num;
	User *users = new User[MAX_ARRAY_SIZE];
	if (readAllUsers(users, num)) {
		cout << "File does not exist.\n";
		doPauseAndCls();
		return 1;
	}

	for (int i = 0; i < num; i++) {
		if (users[i].login != user.login) continue;

		if (users[i].pass == user.pass) {
			cout << "Login successful.\n";
			doPauseAndCls();
			return 0;
		}
		else {
			cout << "Wrong password.\n";
			doPauseAndCls();
			return 1;
		}
	}

	cout << "Unknown login.\n";
	doPauseAndCls();
	return 1;
}
int registerUser() {
	User user = getLoginAndPass();
	user.role = ROLE_USER;
	user.access = NOT_AVAILABLE;

	int num;
	User *users = new User[MAX_ARRAY_SIZE];
	readAllUsers(users, num);

	for (int i = 0; i < num; i++) {
		if (users[i].login == user.login) {
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
User getLoginAndPass() {
	User user;

	cout << "Enter login:\n";
	do {
		getline(cin, user.login);
	} while (!isValidLogin(user.login));

	cout << "Enter password:\n";
	do {
		getline(cin, user.pass);
	} while (!isValidPass(user.pass));

	return user;
}
void coutUsers(User *users, int num) {
	for (int i = 0; i < num; i++) {
		cout << users[i].login << " "
			<< users[i].pass << " "
			<< users[i].role << " "
			<< users[i].access << "\n";
	}
}
void insertUser(User newUser) {
	ofstream fadd(USERS, ios::binary|ios::app);
	fadd.write((char*) &newUser, sizeof newUser);
	fadd.close();
}
bool readAllUsers(User *users, int &num) {
	ifstream fin(USERS, ios::binary|ios::in);

	int m = 0;
	if (!fin.is_open()) {
		return 1;
	} else {
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
int readIntNum() {
	while (1) {
		int num;
		cin >> num;
		if (cin.get() == '\n') {
			return num;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << " Error 1: Value should be type int.\n ";
		}
	}
}
void doPauseAndCls() {
	system("pause");
	system("cls");
}