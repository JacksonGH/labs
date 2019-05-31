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
int editUser();
int deleteUser();

int checkUserLogin(User *, int &, User &);
User editEnterUser(User);
void updateUserInfo(User, int);
void rewriteUsersFile(User *, int);
int enableUser();

char *getLogin();
int getPass();
int getAccess();
int getRole();

int getRoleValueFromName(string);

string getAccessNameFromValue(int);
string getRoleNameFromValue(int);