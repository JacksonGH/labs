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

void coutWorker(Worker);
int addWorker();
Worker editEnterWorker(Worker);
int getNowYear();
bool isValidDate(double);
bool isValidFIO(string);
string getWorkerFio();
double getWorkerDate();
Worker getWorkerInfo();
void insertWorker(Worker);
bool readAllWorkers(Worker *, int &);

int main()
{
	/*password
	cout << "";
	char *pass = new char[100];
	int i = 0;
	char t;
	for (i = 0;;) {
		t = _getch();
		if (t >= 'a' && t <= 'z' || t >= 'A' && t <= 'Z' || t >= '0' && t <= '9') {
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
	system("pause");*/

	if (addWorker() == 0) {
		cout << "SUcessssssssss";
	}
	system("pause");


	User *users = new User[MAX_ARRAY_SIZE];
	int num = 0;
	readAllUsers(users, num);
	coutUsers(users, num);
	system("pause");

	int choice;
	while (entry(choice));

	if (choice == REGISTER) {
		system("pause");
		return 0;
	}

	system("pause");
	return 0;
}
void coutWorker(Worker worker) {
	cout << "FIO: " << worker.fio << "\n"
		<< "Personal number: " << worker.pers_num << "\n"
		<< "Date: " << worker.date << "\n"
		<< "Work hours: " << worker.work_hours << "\n"
		<< "Rate: " << worker.rate << "\n";
}
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

		if (choice == 0)
			return worker;

		switch (choice) {
		case 1:
			cout << "Enter FIO(! as a separator between the lines, use TAB):\n";
			worker.fio = getWorkerFio();
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
			cout << "Unknown option.\n";
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
	int enterYear = floor(date); 
	int nowYear = getNowYear();
	int month = round((date - enterYear) * 100);

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
	regex regular("^[A-Z][a-z]{0,18}(-[A-Z][a-z]{0,18})?\t{1}[A-Z][a-z]{0,18}(\t{1}[A-Z][a-z]{0,18})?$");
	bool valid = std::regex_match(str.c_str(), result, regular);
	if (!valid)
		cout << "FIO must be a string, which can contain minimum surname and name(! as a separator between the lines, use TAB).\n";
	return valid;
}
string getWorkerFio() {
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
	
	cout << "Enter FIO(! as a separator between the lines, use TAB):\n";
	worker.fio = getWorkerFio();

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