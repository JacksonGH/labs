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