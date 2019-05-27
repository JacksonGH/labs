#pragma once
#include "common.h"
#include "auth.h"

void viewAllUsers();
bool readAllUsers(User *, int &);
void coutUsers(User *, int);

int addUser(int access);