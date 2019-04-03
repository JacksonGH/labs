#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Account {
	string name;
	string pass;
	int access;
};

const int SIZE = 20;
const string NAME_OF_FILE = "D://smth_file.txt";

void generateArrUs(Account *users,int &size);
void showArUs(Account *users, int size);
void writeArUs(Account *users, int size);
void writeUs(Account user);
void readFile(Account *users, int &size);

int main() {
	Account users[SIZE];
	int size=0;
	generateArrUs(users,size);
	writeArUs(users, size);
	Account sm;
	sm.name = "kdfks";
	sm.pass = "MKSKDAK";
	sm.access = 0;
	writeUs(sm);
	showArUs(users, size);

	system("pause");
	return 0;
}
void generateArrUs(Account *users,int &size) {
	size = 3;
	users[0].name = "Admin";
	users[0].pass = "smcfogfwqljs";
	users[0].access = 1;
	users[1].name = "Victor";
	users[1].pass = "123";
	users[1].access = 0;
	users[2].name = "Peter";
	users[2].pass = "asjsja";
	users[2].access = 0;
}
void showArUs(Account *users, int size) {
	for (int i = 0; i < size;i++) {
		cout << users[i].name << " " << users[i].pass << " " << users[i].access<<endl;
	}
}
void writeArUs(Account *users, int size) {
	ofstream fout(NAME_OF_FILE, ios::out);
	for (int i = 0; i < size;i++) {
		fout << users[i].name << " " << users[i].pass << " " << users[i].access;
		if (i + 1 < size) {
			fout << endl;
		}
	}
	fout.close();
}
void writeUs(Account user) {
	ofstream fout(NAME_OF_FILE, ios::out);
	fout << endl << user.name << " " << user.pass << " " << user.access;
	fout.close();
}
void readFile(Account *users, int &size) {
	ifstream fin(NAME_OF_FILE, ios::in);
	int i = 0;
	if (!fin.is_open()) cout<< "I can't find file";
	else {
		while (!fin.eof()) {
			fin.read((char *)&users[i],sizeof  users[i]);
			i++;
		}
		size = i;
	}
}