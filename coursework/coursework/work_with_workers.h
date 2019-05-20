#pragma once
#include "common.h"

using namespace std;

const string WORKERS = "D://workers.txt";

const double TAX = 12;
const int OVERTIME_RANGE = 144;

struct Date {
	int year;
	int month;
};

struct Worker {
	char fio[MAX_STR_SIZE];
	int pers_num;
	char date[DATE_SIZE];
	int work_hours;
	double rate;
};

struct Salary {
	char fio[MAX_STR_SIZE];
	int pers_num;
	double salary_per_month;
	double salary_per_range = 0;
};

int addWorker();
Worker editEnterWorker(Worker);
void viewAllWorkers();
void calcAndCoutSalariesForRange(Worker *, int, char *);
void searchWorkers(Worker *, int, int);
void sortWorkers(Worker *, int, int);

void insertWorker(Worker);
bool readAllWorkers(Worker *, int &);
void coutWorkers(Worker *, int);
void coutWorker(Worker);

Worker getWorkerInfo();
char *getWorkerFIO();
char *getWorkerDate();
char *getRange();

bool isValidFIO(char *);
bool isValidDate(char *);
bool isValidRange(char *);

int workersFixture();
double getWorkerSalary(Worker);
Date nowDate();