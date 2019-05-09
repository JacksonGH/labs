#pragma once
#include <iostream>

using namespace std;

const string USERS = "D://users.txt";
const int MAX_ARRAY_SIZE = 100;

struct User
{
	string login;
	string pass;
	bool role;
	bool access;
};

int readIntNum();
double readDoubleNum();
int readPosIntNum();
double readPosDoubleNum();
void doPauseAndCls();