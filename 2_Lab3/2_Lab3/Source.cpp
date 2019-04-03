#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

struct Stack {
	double info;
	Stack *next;
} *beginStack;

double readIntNum();
Stack* inStack(Stack *, int);
void view(Stack *);
void sort_info(Stack *);
double calcAvgStack(Stack *);
Stack* rmAvgStack(Stack *, int &);
Stack* inAvgStack(Stack *p, double in);

int main() {
	srand(time(NULL));

	int stop = 0;
	do {
		cout <<
			"Instruction:\n"
			" 0 to generate random stack from -20 to 20\n"
			" 1 to add a new item\n"
			" 2 to view all items\n"
			" 3 to remove all items, that are less than the average\n"
			" 4 to sort all items\n"
			" 5 to exit\n"
			"Enter: "
			;
		int choice = readIntNum();
		switch (choice) {
		case 0:
		{
			do {
				cout << "Select the number of stack items: ";
				choice = readIntNum();
			} while (choice <= 0);

			int a = -20, b = 20;
			while (choice--) {
				int newElem = rand() % (b - a + 1) + a;
				beginStack = inStack(beginStack, newElem);
			}
			break;
		}
		case 1:
		{
			cout << "Enter new item: ";
			int newElem = readIntNum();
			beginStack = inStack(beginStack, newElem);
			break;
		}
		case 2:
			view(beginStack);
			system("pause");
			break;
		case 3:
		{
			cout << "Old stack:\n";
			view(beginStack);

			Stack *t = beginStack;
			int count = 0;
			beginStack = rmAvgStack(t, count);

			cout << "Delete items: " << count << "\n";
			cout << "New stack:\n";
			view(beginStack);

			system("pause");
			break;
		}
		case 4:
			sort_info(beginStack);
			break;
		case 5:
			stop = 1;
			break;
		case 6:
		{
			cout << "Old stack:\n";
			view(beginStack);

			Stack *t = beginStack;
			double averageNum = calcAvgStack(t);
			beginStack = inAvgStack(t, averageNum);

			cout << "Add item: " << averageNum << "\n";
			cout << "New stack:\n";
			view(beginStack);

			system("pause");
			break;
		}
		}
		system("cls");
	} while (!stop);

	return 0;
}
Stack* inAvgStack(Stack *p, double in) {
	Stack *add = new Stack;
	add->info = in;

	int strlen = 0;
	Stack *t = p;
	while (t != NULL) {
		t = t->next;
		strlen++;
	}
	Stack *prev = p;
	t = p;
	for (int i = 0; i < strlen/2; i++) {
		prev = t;
		t = t->next;
	}
	prev->next = add;
	add->next = t;
	
	return p;
}
Stack* inStack(Stack *p, int in) {
	Stack *t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}
void view(Stack *p) {
	Stack *t = p;
	for (int i = 1; t != NULL; i++, t = t->next) {
		cout << i << " - " << t->info << '\n';
	}
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
void sort_info(Stack *p) {
	Stack *t = NULL, *t1;
	int r;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info) {
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;
	} while (p->next != t);
}
double calcAvgStack(Stack *t) {
	int sum = 0, count = 0;
	while (t != NULL) {
		sum += t->info;
		count++;
		t = t->next;
	}
	return (double)sum / count;
}
Stack* rmAvgStack(Stack *t, int &count) {
	double average = calcAvgStack(t);
	cout << "Average value is " << average << "\n";

	t = inStack(t, 0);
	Stack *prev = t, *t1 = t->next;
	while (t1 != NULL) {
		if (t1->info < average) {
			prev->next = t1->next;
			count++;
		}
		else {
			prev = t1;
		}
		t1 = t1->next;
	}
	Stack *temp = t;
	t = t->next;
	delete temp;
	return t;
}