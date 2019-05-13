#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "auth.h"
#include <time.h>
#include <regex>
#include <string>
#include <iomanip>

using namespace std;

const string WORKERS = "D://workers.txt";

const int CONFIRM = 1;
const int EDIT = 2;
const int CANCEL = 3;

struct Worker {
	char fio[MAX_STR_SIZE];
	int pers_num;
	double date;
	int work_hours;
	double rate;
};

//modules
int mainApp(User *);
//user
int userApp(User *);
void viewAllWorkers();
void coutWorkers(Worker *, int);
void coutWorker(Worker);

//another
int workersFixture();
int addWorker();
Worker editEnterWorker(Worker);
int getNowYear();
bool isValidDate(double);
bool isValidFIO(char *);
char *getWorkerFIO();
double getWorkerDate();
Worker getWorkerInfo();
void insertWorker(Worker);
bool readAllWorkers(Worker *, int &);

int main()
{
	//cout users
	/*User *users = new User[MAX_ARRAY_SIZE];
	int num;
	readAllUsers(users, num);
	coutUsers(users, num);*/

	//add workers 
	//if (workersFixture() == 0) cout << "Succeesss";
	//system("pause");

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
//admin
int adminApp(User *user) {
	return EXIT_OPTION;
}
//modules
int mainApp(User *user) {
	if (user->role == ROLE_ADMIN)
		return adminApp(user);

	return userApp(user);
}
//user
int userApp(User *user) {
	int choice;
	while (1) {
		cout << "Login: " << user->login << '\n' <<
			"Choose what you want:\n"
			" 1.view all data about workers\n"
			" 2.calculate the wages of all employees for a certain period of time\n"
			" 3.search data about workers\n"
			" 4.sort data about workers\n"
			" 5.logout(back to auth)\n"
			" 0.exit\n";
		choice = readIntNum();
		system("cls");

		switch (choice) {
		case EXIT_OPTION:
			return EXIT_OPTION;
		case 1:
			viewAllWorkers();
			doPauseAndCls();
			break;
		case 5: 
		{
			int choice;
			User *user = new User;
			while (auth(choice, user));
			return EXIT_OPTION;
		}
		default:
			cout << "Unknown option: " << choice << '\n';
			doPauseAndCls();
		}
	}
}
void viewAllWorkers() {
	Worker *worker = new Worker[MAX_ARRAY_SIZE];
	int num = 0;
	readAllWorkers(worker, num);
	coutWorkers(worker, num);
}
void coutWorkers(Worker *workers, int num) {
	cout << left << setw(18) << "Personal Number"
		<< setw(10) << "Date"
		<< setw(13) << "Work hours"
		<< setw(10) << "Rate"
		<< '\n' << setfill('-') << setw(80) << "" << setfill(' ') << '\n';

	for (int i = 0; i < num; i++)
		cout << setw(80) << workers[i].fio << '\n'
			<< setw(18) << workers[i].pers_num
			<< setw(10) << workers[i].date
			<< setw(13) << workers[i].work_hours
			<< setw(10) << workers[i].rate << '\n'
			<< setfill('-') << setw(80) << "" << setfill(' ') << '\n';
}
void coutWorker(Worker worker) {
	cout << "FIO: " << worker.fio << '\n'
		<< "Personal number: " << worker.pers_num << '\n'
		<< "Date: " << worker.date << '\n'
		<< "Work hours: " << worker.work_hours << '\n'
		<< "Rate: " << worker.rate << '\n';
}

//another
int workersFixture() {
	int num = 6;
	Worker *workers = new Worker[num];
	string arr_fio[] = {
		"Andrew Brown",
		"Pavel Petrov",
		"Ivannivannivann",
		"Ivan I P",
		"Ivan Ivanovich I",
		"New Try"
	};
	double arr_date[] = {
		2019.5, 2019.4, 2019.3, 2019.2, 2019.1,
		2018.12, 2018.11, 2018.10, 2018.09, 2018.08,
	};

	int numFromFile;
	Worker *workersFromFile = new Worker[MAX_ARRAY_SIZE];
	readAllWorkers(workersFromFile, numFromFile);
	for (int i = 0; i < num * 10; i++) {
		strcpy(workers[i].fio, arr_fio[i].c_str());
		workers[i].date = 2019.6;
		workers[i].pers_num = (i + 1) * 100;
		workers[i].work_hours = i + 100;
		workers[i].rate = i + 10;

		if (workersFromFile[i].pers_num == workers[i].pers_num && workersFromFile[i].fio != workers[i].fio) {
			cout << "You cannot create records with the same personal number and differecnts FIO.\n";
			doPauseAndCls();
			return 1;
		}
		if (workersFromFile[i].pers_num == workers[i].pers_num && workersFromFile[i].date == workers[i].date) {
			cout << "You cannot create records with the same date for one worker.\n";
			doPauseAndCls();
			return 1;
		}
		insertWorker(workers[i]);
	}

	return 0;
}
int addWorker() {
	Worker worker = getWorkerInfo();

	int num;
	Worker *workers = new Worker[MAX_ARRAY_SIZE];
	readAllWorkers(workers, num);

	for (int i = 0; i < num; i++) {
		if (workers[i].pers_num == worker.pers_num && workers[i].fio != worker.fio) {
			cout << "You cannot create records with the same personal number and differecnts FIO.\n";
			doPauseAndCls();
			return 1;
		}
		if (workers[i].pers_num == worker.pers_num && workers[i].date == worker.date) {
			cout << "You cannot create records with the same date for one worker.\n";
			doPauseAndCls();
			return 1;
		}
	}
	system("cls");

	int choice;
	while (1) {
		coutWorker(worker);
		cout << "Choose what you want:\n"
			" 1.confirm\n"
			" 2.edit\n"
			" 3.cancel\n";
		choice = readIntNum();
		system("cls");

		if (choice == EDIT)
			worker = editEnterWorker(worker);
		else if (choice == CONFIRM) {
			insertWorker(worker);
			cout << "Successful added worker info.\n"; 
			doPauseAndCls();
			return 0;
		} else if (choice == CANCEL) {
			cout << "Added worker canceled.\n";
			doPauseAndCls();
			return 0;
		}
	}
}
Worker editEnterWorker(Worker worker) {
	int choice;
	while (1) {
		coutWorker(worker);
		cout << "Choose what you want edit:\n"
			" 1.FIO\n"
			" 2.personal number\n"
			" 3.date\n"
			" 4.work hours\n"
			" 5.rate\n"
			" 0.exit\n";
		choice = readIntNum();
		system("cls");

		switch (choice) {
		case EXIT_OPTION:
			return worker;
		case 1:
			cout << "Enter FIO:\n";
			strcpy(worker.fio, getWorkerFIO());
			system("cls");
			break;
		case 2:
			cout << "Enter personal number:\n";
			worker.pers_num = readPosIntNum();
			system("cls");
			break;
		case 3:
			cout << "Enter year and month(! in format year.month):\n";
			worker.date = getWorkerDate();
			system("cls");
			break;
		case 4:
			cout << "Enter work hours(! int number):\n";
			worker.work_hours = readPosIntNum();
			system("cls");
			break;
		case 5:
			cout << "Enter rate(! can be double number):\n";
			worker.rate = readPosDoubleNum();
			system("cls");
			break;
		default:
			cout << "Unknown option: " << choice << '\n';
		}
	}
}
int getNowYear() {
	struct tm localtime;
	time_t now = time(NULL);
	localtime_s(&localtime, &now);
	return localtime.tm_year + 1900;
}
bool isValidDate(double date) {
	int enterYear = floor(date),
		nowYear = getNowYear(),
		month = round((date - enterYear) * 100);

	if (month % 10 == 0) {
		month /= 10;
	}

	if (enterYear > nowYear + 2 || enterYear < nowYear - 2) {
		cout << "Wrong year(year must be a number not larger than the current year by 2 and not less than the current year by 2).\n";
		return false;
	}

	if (month != (int)month || month < 1 || month > 12) {
		cout << "Wrong month(month must be a number from 1 to 12).\n";
		return false;
	}

	return true;
}
bool isValidFIO(char *str) {
	cmatch result;
	regex regular("^[A-Z][a-z]{0,18}(-[A-Z][a-z]{0,18})? {1}[A-Z][a-z]{0,18}( {1}[A-Z][a-z]{0,18})?$");
	bool valid = std::regex_match(str, result, regular);
	if (!valid)
		cout << "FIO must be a string, which can contain minimum surname and name(word cannot be more than 19, if the surname is compound then 38 excluding hyphens).\n";
	return valid;
}
char *getWorkerFIO() {
	char fio[MAX_STR_SIZE];
	do {
		cin.getline(fio, sizeof fio);
	} while (!isValidFIO(fio));
	return fio;
}
double getWorkerDate() {
	double date;
	do {
		date = readDoubleNum();
	} while (!isValidDate(date));
	return date;
}
Worker getWorkerInfo() {
	Worker worker;
	
	cout << "Enter FIO:\n";
	strcpy(worker.fio, getWorkerFIO());

	cout << "Enter personal number:\n";
	worker.pers_num = readPosIntNum();

	cout << "Enter year and month(! in format year.month):\n";
	worker.date = getWorkerDate();

	cout << "Enter work hours(! int number):\n";
	worker.work_hours = readPosIntNum();

	cout << "Enter rate(! can be double number):\n";
	worker.rate = readPosDoubleNum();

	return worker;
}
void insertWorker(Worker worker) {
	ofstream fadd(WORKERS, ios::binary|ios::app);
	fadd.write((char*) &worker, sizeof worker);
	fadd.close();
}
bool readAllWorkers(Worker *workers, int &num) {
	ifstream fin(WORKERS, ios::binary | ios::in);

	int m = 0;
	if (!fin.is_open()) {
		return 1;
	}
	else {
		while (!fin.eof()) {
			fin.read((char*)&workers[m], sizeof workers[m]);
			m++;
		}
		fin.close();
		m--;
	}
	num = m;

	return 0;
}