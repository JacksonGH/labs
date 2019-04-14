#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>

using namespace std;

struct Stack {
	char info;
	Stack *prev, *next;
} *beginQueue, *endQueue;

double calcAvgQueue(Stack *);
Stack* rmAvgQueue(Stack *, int &);
double readIntNum();
void viewFromBegin(Stack *);
void viewFromEnd(Stack *);

int main() {
	srand(time(NULL));

	int stop = 0;
	do {
		cout <<
			"Instruction:\n"
			" 1 to use default value: a*(b+c)/(d-e) with a=0.4, b=2.3, c=6.7, d=5.8, e=9.1\n"
			" 2 to enter own values\n"
			" 5 to exit\n"
			"Enter: "
			;
		int choice = readIntNum();
		string inputStr;
		switch (choice) {
		case 1:
		{
			inputStr = "a*(b+c)/(d-e)";
			cout << inputStr;
			system("pause");
			Stack *t;
			while (choice--) {
				t = new Stack;
				//t->info = rand() % (b - a + 1) + a;
				t->next = NULL;
				if (beginQueue == NULL) {
					t->prev = NULL;
					beginQueue = endQueue = t;
					continue;
				}
				t->prev = endQueue;
				endQueue->next = t;
				endQueue = t;
			}

			viewFromBegin(beginQueue);
			system("pause");
			break;
		}
		case 2:
		{
			getline(cin, inputStr);
			cout << inputStr;
			system("pause");

			Stack *t = new Stack;
			//t->info = ????;
			if (beginQueue == NULL) {
				t->next = NULL;
				t->prev = NULL;
				beginQueue = endQueue = t;
			}
			else if (choice == 1) {
				t->prev = NULL;
				t->next = beginQueue;
				beginQueue->prev = t;
				beginQueue = t;
			}
			else {
				t->prev = endQueue;
				t->next = NULL;
				endQueue->next = t;
				endQueue = t;
			}
			break;
		}
		case 5:
			stop = 1;
			break;
		}
		system("cls");
	} while (!stop);

	return 0;
}
double readIntNum() {
	while (1) {
		int num;
		cin >> num;
		if (cin.get() == '\n') {
			return num;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << " Error 1: Value should be type int.\n ";
		}
	}
}
void viewFromBegin(Stack *b) {
	Stack *t = b;
	for (int i = 1; t != NULL; i++, t = t->next) {
		cout << i << " - " << t->info << '\n';
	}
}
void viewFromEnd(Stack *e) {
	Stack *t = e;
	for (int i = 1; t != NULL; i++, t = t->prev) {
		cout << i << " - " << t->info << '\n';
	}
}