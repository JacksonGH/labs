#pragma once
#include "common.h"
#include "auth.h"

void viewAllUsers();
bool readAllUsers(User *, int &);
void coutUsers(User *, int);
void coutUser(User);

int addUser(int);
void searchUsers(User *, int, int);
void sortUsers(User *, int, int);

string getAccessNameFromValue(int);
string getRoleNameFromValue(int);