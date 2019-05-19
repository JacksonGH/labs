#pragma once
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

const string USERS = "D://users.txt";
const int MAX_ARRAY_SIZE = 100;
const int MAX_STR_SIZE = 81;
const int DATE_SIZE = 8;

const int ROLE_ADMIN = 1;
const int ROLE_USER = 0;

const int AVAILABLE = 1;
const int NOT_AVAILABLE = 0;

const int EXIT_OPTION = 0;

struct User
{
	char login[MAX_STR_SIZE];
	unsigned long pass;
	int role = ROLE_USER;
	bool access = NOT_AVAILABLE;
};

int readIntNum();
double readDoubleNum();
int readPosIntNum();
double readPosDoubleNum();
void doPauseAndCls();