#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stdio.h>//работа с файлами в C
#include <io.h>//работа с файлами в C
#include <string>
#include <conio.h>//_getch()

using namespace std;

const int SIZE = 81;
const char FILE_NAME[SIZE] = "D://work//file.txt";

void encodeMessage(char*);//возвращать значение
void decodeMessage(char*);//возвращать значение

int endOrRepeat();

int main() {

	do {
		FILE *file;
		char str[SIZE], choice[SIZE];

		printf("Select what you want to do with the file (enter \"write\" or \"read\"): ");
		gets_s(choice);

		if (!strcmp(choice, "write")) {
			if (!(file = fopen(FILE_NAME, "a"))) {
				printf("Error of opening file\n");
				return 1;
			}

			printf("Enter string to write: ");
			gets_s(str);
			encodeMessage(str);
			printf("Task write as: %s\n", str);
			fprintf(file, "%s\n", str);

			fclose(file);
		}
		else if (!strcmp(choice, "read")) {
			if (!(file = fopen(FILE_NAME, "r"))) {
				printf("Error of opening file\n");
				return 1;
			}

			printf("Select what you want to read ( enter \"all\" to output all records or \"last\" to output last record ): ");
			gets_s(choice);

			while (fgets(str, SIZE, file)) {
				for (int i = 0; i < SIZE; i++)
					if (str[i] == '\n') str[i] = '\0';
				if (!strcmp(choice, "all")) {
					printf("%s - ", str);
					decodeMessage(str);
					printf("%s\n", str);
				}
			}
			if (!strcmp(choice, "last")) {
				printf("%s - ", str);
				decodeMessage(str);
				printf("%s\n", str);
			}

			fclose(file);
		}
		else cout << "You should write \"write\" or \"read\"\n";

	} while (endOrRepeat());

	return 0;
}
void encodeMessage(char* str) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'Z')
			str[i] = 'A';
		else if (str[i] == 'z')
			str[i] = 'a';
		else if ((int)str[i] >= (int)'A' && (int)str[i] < (int)'Z' || (int)str[i] >= (int)'a' && (int)str[i] < (int)'z')
			str[i] = (char)((int)str[i] + 1);
	}
}
void decodeMessage(char* str) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'A')
			str[i] = 'Z';
		else if (str[i] == 'a')
			str[i] = 'z';
		else if ((int)str[i] > (int)'A' && (int)str[i] <= (int)'Z' || (int)str[i] > (int)'a' && (int)str[i] <= (int)'z')
			str[i] = (char)((int)str[i] - 1);
	}
}
int endOrRepeat() {
	cout << "If you want to continue, press any key. If you want to exit the program, press ESC.\n";
	if (_getch() == 27) return 0;
	_getch();
	return 1;
}