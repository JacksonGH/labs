#include <iostream>
#include <conio.h>
#include "entry.h"
#include <time.h>
#include <regex>
#include <string>

using namespace std;

const string WORKERS = "D://workers.txt";

const int CONFIRM = 1;
const int EDIT = 2;
const int CANCEL = 3;

struct Worker {
	string fio;
	int pers_num;
	double date;
	int work_hours;
	int rate;
};

//user
int userDo(User *);
void viewAllWorkers();
void coutWorkers(Worker *, int);
void coutWorker(Worker);

//another
int addWorker();
Worker editEnterWorker(Worker);
int getNowYear();
bool isValidDate(double);
bool isValidFIO(string);
string getWorkerFIO();
double getWorkerDate();
Worker getWorkerInfo();
void insertWorker(Worker);
bool readAllWorkers(Worker *, int &);

int main()
{	
	//add worker
	/*if (addWorker() == 0) {
		cout << "SUcessssssssss";
	}
	system("pause");*/

	//cout all users
	/*User *users = new User[MAX_ARRAY_SIZE];
	int num = 0;
	readAllUsers(users, num);
	coutUsers(users, num);
	system("pause");*/

	/*int choice;
	User *user = new User;
	entry(choice, user);
	system("pause");*/

	/*hash <std::string> hash;
	string passwordGuess = "qwerty";
	string passwordGuess1 = "qwerty1";
	unsigned long hashedPasswordGuess = hash(passwordGuess);
	cout << hashedPasswordGuess << '\n';
	cout << hash(passwordGuess1) << '\n';
	cout << hash("qwerty2") << '\n';
	system("pause");*/

	int choice;
	User *user = new User;
	while (entry(choice, user));

	if (choice == REGISTER) {
		system("pause");
		return 0;
	}

	//new module(user)
	while(userDo(user));

	system("pause");
	return 0;
}
//user
int userDo(User *user) {
	int choice;
	while (1) {
		cout << "Login: " << user->login << '\n' <<
			"Choose what you want:\n"
			" 1.view all data about workers\n"
			" 2.calculate the wages of all employees for a certain period of time\n"
			" 3.search data about workers\n"
			" 4.sort data about workers\n";
			" 0.exit\n";
		choice = readIntNum();
		system("cls");

		switch (choice) {
		case 0:
			return 0;
		case 1: 
			viewAllWorkers();
			doPauseAndCls();
			break;
		default:
			cout << "Unknown option: " << choice << '\n';
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
	for (int i = 0; i < num; i++)
		cout << "FIO: " << workers[i].fio << '\n'
		<< "Personal number: " << workers[i].pers_num << '\n'
		<< "Date: " << workers[i].date << '\n'
		<< "Work hours: " << workers[i].work_hours << '\n'
		<< "Rate: " << workers[i].rate << '\n';
}
void coutWorker(Worker worker) {
	cout << "FIO: " << worker.fio << '\n'
		<< "Personal number: " << worker.pers_num << '\n'
		<< "Date: " << worker.date << '\n'
		<< "Work hours: " << worker.work_hours << '\n'
		<< "Rate: " << worker.rate << '\n';
}

//another
int addWorker() {
	Worker worker = getWorkerInfo();

	int num;
	Worker *workers = new Worker[MAX_ARRAY_SIZE];
	readAllWorkers(workers, num);

	for (int i = 0; i < num; i++) {
		if (workers[i].pers_num == worker.pers_num && workers[i].fio == worker.fio) {
			cout << "You cannot create records with the same personal number and differecnts FIO.\n";
			doPauseAndCls();
			return 1;
		}
		if (workers[i].date == worker.date) {
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
		case 0:
			return worker;
		case 1:
			cout << "Enter FIO(! as a separator between the lines, use TAB):\n";
			worker.fio = getWorkerFIO();
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
bool isValidFIO(string str) {
	cmatch result;
	/*
	Valid FIO:
	- Petrov-Ivanov Ivan
	- Petrov-Ivanov I
	- Petrov-Ivanov Ivan Aleksondrovich
	- Petrov-Ivanov I A
	*/
	regex regular("^[A-Z][a-z]{0,20}(-[A-Z][a-z]{0,20})? {1}[A-Z][a-z]{0,20}( {1}[A-Z][a-z]{0,20})?$");
	bool valid = std::regex_match(str.c_str(), result, regular);
	if (!valid)
		cout << "FIO must be a string, which can contain minimum surname and name(word cannot be more than 20, if the surname is composite then 40).\n";
	return valid;
}
string getWorkerFIO() {
	string fio;
	do {
		getline(cin, fio);
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
	worker.fio = getWorkerFIO();

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
	ofstream fadd(WORKERS, ios::binary | ios::app);
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