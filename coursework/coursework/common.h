#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <regex>
#include <fstream>

using namespace std;

const string USERS = "D://users.txt";

const int MAX_ARRAY_SIZE = 100;
const int MAX_STR_SIZE = 81;
const int DATE_SIZE = 8;

const string ROLE_SUPER_ADMIN_NAME = "super admin";
const string ROLE_ADMIN_NAME = "admin";
const string ROLE_USER_NAME = "user";
const int ROLE_SUPER_ADMIN_VALUE = 2;
const int ROLE_ADMIN_VALUE = 1;
const int ROLE_USER_VALUE = 0;

const int AVAILABLE = 1;
const int NOT_AVAILABLE = 0;

const int EXIT_OPTION = 0;

const int CONFIRM = 1;
const int EDIT = 2;
const int CANCEL = 3;

struct User
{
	char login[MAX_STR_SIZE];
	unsigned long pass;
	int role = ROLE_USER_VALUE;
	bool access = NOT_AVAILABLE;
};

int readIntNum();
double readDoubleNum();
int readPosIntNum();
double readPosDoubleNum();
void doPauseAndCls();