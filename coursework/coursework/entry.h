#pragma once
#include <regex>
#include <fstream>
#include "common.h"

using namespace std;

const int LOGIN = 1;
const int REGISTER = 2;

int loginUser(User *);
int registerUser(User *);
int entry(int &, User *);

void getLoginAndPass(User *);

bool readAllUsers(User *, int &);
void insertUser(User *);

void coutUsers(User *, int);

bool isValidLogin(string);
bool isValidPass(string);