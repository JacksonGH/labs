#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "common.h"

using namespace std;

const int LOGIN = 1;
const int REGISTER = 2;

const int ROLE_ADMIN = 1;
const int ROLE_USER = 0;

const int AVAILABLE = 1;
const int NOT_AVAILABLE = 0;

int loginUser();
int registerUser();
int entry(int&);

User getLoginAndPass();

bool readAllUsers(User *, int &);
void insertUser(User);

void coutUsers(User *, int);

bool isValidLogin(string);
bool isValidPass(string);