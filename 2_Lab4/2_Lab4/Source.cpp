#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

struct Queue {
	int info;
	Queue *prev, *next;
} *beginQueue, *endQueue;

Queue* addBeforeNumFromBegin(Queue *, int , int );
double calcAvgQueue(Queue *);
void rmAvgQueue(Queue **, Queue **, int &);
int readIntNum();
void viewFromBegin(Queue *);
void viewFromEnd(Queue *);

int main() {
	srand(time(NULL));

	int stop = 0;
	do {
		cout <<
			"Instruction:\n"
			" 0 to add generate random queue at the end from -20 to 20\n"
			" 1 to add a new item\n"
			" 2 to view all items\n"
			" 3 to remove all items, that are less than the average\n"
			" 4 to add elem before number(start from begin queue)\n"
			" 5 to exit\n"
			"Enter: "
			;
		int choice = readIntNum();
		switch (choice) {
		case 0:
		{
			do {
				cout << "Select the number of queue items: ";
				choice = readIntNum();
			} while (choice <= 0);

			int a = -20, b = 20;
			
			Queue *t;
			while (choice--) {
				t = new Queue;
				t->info = rand() % (b - a + 1) + a;
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
		case 1:
		{
			do {
				cout <<
					"Enter\n"
					" 1 to add elem at the start of queue\n"
					" 2 to add elem at the end of queue\n";
				choice = readIntNum();
			} while (choice != 1 && choice != 2);

			cout <<
				"Enter elem: \n";
			int elem = readIntNum();

			Queue *t = new Queue;
			t->info = elem;
			if (beginQueue == NULL) {
				t->next = NULL;
				t->prev = NULL;
				beginQueue = endQueue = t;
			} else if (choice == 1) {
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
		case 2:
		{
			do {
				cout <<
					"Enter\n"
					" 1 to view queue from the start\n"
					" 2 to view queue form the end\n";
				choice = readIntNum();
			} while (choice != 1 && choice != 2);

			if (choice == 1) {
				viewFromBegin(beginQueue);
			}
			else {
				viewFromEnd(endQueue);
			}
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Old queue:\n";
			viewFromBegin(beginQueue);

			//Queue *t = beginQueue;
			int count = 0;
			rmAvgQueue(&beginQueue, &endQueue, count);

			cout << "Delete items: " << count << "\n";
			cout << "New queue:\n";
			viewFromBegin(beginQueue);
			cout << "-------";
			viewFromEnd(endQueue);

			system("pause");
			break;
		}
		case 4:
		{
			cout << "Old queue:\n";
			viewFromBegin(beginQueue);

			cout << "Add elem:";
			int add = readIntNum();
			cout << "After elem:";
			int after = readIntNum();

			beginQueue = addBeforeNumFromBegin(beginQueue, add, after);

			cout << "New queue:\n";
			viewFromBegin(beginQueue);

			system("pause");
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
Queue* addBeforeNumFromBegin(Queue *b, int add, int after) {
	Queue *t = b, *newElem = new Queue;

	while (t->info != after)
		t = t->next;
	if (t != NULL) {
		newElem->info = add;
		newElem->next = t->next;
		t->next = newElem;
		newElem->prev = t;
		newElem->next->prev = newElem;
	}

	return b;
}
int readIntNum() {
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
void viewFromBegin(Queue *b) {
	Queue *t = b;
	for (int i = 1; t != NULL; i++, t = t->next) {
		cout << i << " - " << t->info << '\n';
	}
}
void viewFromEnd(Queue *e) {
	Queue *t = e;
	for (int i = 1; t != NULL; i++, t = t->prev) {
		cout << i << " - " << t->info << '\n';
	}
}
double calcAvgQueue(Queue *t) {
	int sum = 0, count = 0;
	while (t != NULL) {
		sum += t->info;
		count++;
		t = t->next;
	}
	return (double)sum / count;
}
void rmAvgQueue(Queue **b, Queue **e, int &count) {//!!!кроме начала переопределять и конец
	double average = calcAvgQueue(*b);
	cout << "Average value is " << average << "\n";

	Queue *p = new Queue;
	p->info = 0;
	p->prev = NULL;
	p->next = *b;
	(*b)->prev = p;
	*b = p;

	Queue *t1 = (*b)->next;
	while (t1 != NULL) {
		if (t1->info < average) {
			//if (t1->prev != NULL)
			t1->prev->next = t1->next;
			
			if (t1->next != NULL)
				t1->next->prev = t1->prev;
			else {
				*e = t1->prev;
				t1->prev = NULL;
			}
			count++;
		}
		t1 = t1->next;
	}
	Queue *temp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	delete temp;
}