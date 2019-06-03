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
int editUser(User *);
int deleteUser(User *);

int checkUserLogin(User *, int &, User &);
User editEnterUser(User, User *);
void updateUserInfo(User, int);
void rewriteUsersFile(User *, int);
void deleteUserInArray(User *, int &, int);
int enableUser(User *);

char *getLogin();
int getPass();
int getAccess();
int getRole();

int getRoleValueFromName(string);

string getAccessNameFromValue(int);
string getRoleNameFromValue(int);