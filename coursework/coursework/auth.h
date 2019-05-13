#pragma once
#include <regex>
#include <fstream>
#include "common.h"
//test for coutUsers
#include <iomanip>

using namespace std;

const string ACCESS_DENIED = "You get access to the resource as soon as the administrator confirms your account\n";

const int LOGIN = 1;
const int REGISTER = 2;

const string SALT = "kasd83mfds";

int auth(int &, User *);
int loginUser(User *);
int registerUser(User *);

void getLoginAndPass(User *);

bool readAllUsers(User *, int &);
void insertUser(User *);

void coutUsers(User *, int);

bool isValidLogin(char *);
bool isValidPass(char *);