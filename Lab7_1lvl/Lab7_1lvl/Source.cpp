#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <io.h>
#include <string>
#include <conio.h>

using namespace std;

const int SIZE = 26;
const char FILE_NAME[SIZE] = "D://work//file_1lvl.txt";

struct FIO {
	char name[SIZE];
	char surname[SIZE];
	char lastname[SIZE];
};
struct Mark {
	int physics;
	int math;
	int informatic;
	int chemistry;
};
struct Student {
	FIO fio;
	int birthYear;
	int groupNum;
	Mark marks;
	double averageMark;
};

char *readStr(const char *, int);
int readIntWithBord(const char *, int, int);
char *readStr();
char* dynStr(char *);
int strLen(char *);

int endOrRepeat();

int main() {

	FILE *file;
	Student stud;

	do {
		printf("Choose method work with file(enter \"read\" or \"create\"): ");
		char *choice = readStr();

		if (!strcmp(choice, "read")) {
			if (!(file = fopen(FILE_NAME, "r"))) {
				cout << "Error of opening file\n";
				return 1;
			}

			while (fscanf(file, "%s%s%s %i%i%i%i%i%i%lf", stud.fio.name, stud.fio.surname, stud.fio.lastname, &(stud.birthYear), &(stud.groupNum),
				&(stud.marks.physics), &(stud.marks.math), &(stud.marks.informatic), &(stud.marks.chemistry), &(stud.averageMark)) != EOF) {
				printf("%s %s %s %i %i %i %i %i %i %.2lf\n", stud.fio.name, stud.fio.surname, stud.fio.lastname, stud.birthYear, stud.groupNum,
					stud.marks.physics, stud.marks.math, stud.marks.informatic, stud.marks.chemistry, stud.averageMark);
			}
			fclose(file);
		}
		else if (!strcmp(choice, "create")) {
			if (!(file = fopen(FILE_NAME, "a"))) {
				cout << "Error of opening file\n";
				return 1;
			}

			strcpy(stud.fio.name, readStr("name", 1));
			strcpy(stud.fio.surname, readStr("surname", 1));
			strcpy(stud.fio.lastname, readStr("lastname", 1));
			stud.birthYear = readIntWithBord("birth year", 1950, 2002);
			stud.groupNum = readIntWithBord("group number", 100000, 1000000);
			stud.marks.physics = readIntWithBord("physics", 0, 10);
			stud.marks.math = readIntWithBord("math", 0, 10);
			stud.marks.informatic = readIntWithBord("informatic", 0, 10);
			stud.marks.chemistry = readIntWithBord("chemistry", 0, 10);
			stud.averageMark = (stud.marks.physics + stud.marks.math + stud.marks.informatic + stud.marks.chemistry) / 4.;

			printf("You safe string: \n%s %s %s %i %i %i %i %i %i %.2lf\n",
				stud.fio.name, stud.fio.surname, stud.fio.lastname, stud.birthYear, stud.groupNum,
				stud.marks.physics, stud.marks.math, stud.marks.informatic, stud.marks.chemistry, stud.averageMark);
			fprintf(file, "\n%s %s %s %i %i %i %i %i %i %.2lf", stud.fio.name, stud.fio.surname, stud.fio.lastname, stud.birthYear, stud.groupNum,
				stud.marks.physics, stud.marks.math, stud.marks.informatic, stud.marks.chemistry, stud.averageMark);
			fclose(file);
		}

		delete choice;
	} while (endOrRepeat());

	return 0;
}
char *readStr(const char *fio, int bord) {
	char name[SIZE];
	do {
		printf("Enter name: ");
		scanf("%s", name);
	} while (strLen(name) < bord && strLen(name) > SIZE);
	return dynStr(name);
}
int readIntWithBord(const char *subj, int lessBord, int highBord) {
	int mark;
	do {
		printf("Enter your mark in %s: ", subj);
		scanf("%i", &mark);
	} while (mark < lessBord || mark > highBord);
	return mark;
}
char *readStr() {
	char str[SIZE];
	gets_s(str);
	return dynStr(str);
}
char* dynStr(char *str) {
	int len = strLen(str);
	char *dynStr = new char[len + 1];
	strcpy_s(dynStr, len + 1, str);
	return dynStr;
}
int strLen(char *str) {
	int i = 0;
	do {
		++i;
	} while (str[i] != '\0');
	return i;
}
int endOrRepeat() {
	cout << "If you want to continue, press any key. If you want to exit the program, press ESC.\n";
	if (_getch() == 27) return 0;
	_getch();
	return 1;
}