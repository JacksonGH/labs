#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>

using namespace std;

const int SIZE = 81;
double arr[201];

struct Stack {
	char c;
	Stack  *next;
} *op;

double readDoubleNum();
int priority(char);
Stack* inStack(Stack*, char);
Stack* outStack(Stack*, char*);
double result(char*);

int main() {
	Stack *t;
	op = NULL;
	char a, in[SIZE], out[SIZE];

	int k = 0, l = 0;
	cout << "Input formula: ";
	cin >> in;

	while (in[k] != '\0') {
		if (in[k] >= 'a' && in[k] <= 'z')
			out[l++] = in[k];

		if (in[k] == '(')
			op = inStack(op, in[k]);

		if (in[k] == ')') {
			while ((op->c) != '(') {
				op = outStack(op, &a);
				if (!op) a = '\0';
				out[l++] = a;
			}
			t = op;
			op = op->next;
			delete t;
		}
		if (in[k] == '+' || in[k] == '-' || in[k] == '*' || in[k] == '/') {
			while (op != NULL && priority(op->c) >= priority(in[k])) {
				op = outStack(op, &a);
				out[l++] = a;
			}
			op = inStack(op, in[k]);
		}
		k++;
	}

	while (op != NULL) {
		op = outStack(op, &a);
		out[l++] = a;
	}
	out[l] = '\0';
	cout << "Polish:\n" << out << '\n';

	cout << "Input a: ";
	double userA = readDoubleNum();
	cout << "Input b: ";
	double userB = readDoubleNum();
	cout << "Input c: ";
	double userC = readDoubleNum();
	cout << "Input d: ";
	double userD = readDoubleNum();
	cout << "Input e: ";
	double userE = readDoubleNum();

	arr[int('a')] = userA;
	arr[int('b')] = userB;
	arr[int('c')] = userC;
	arr[int('d')] = userD;
	arr[int('e')] = userE;
	//}
	cout << "Result is " << result(out) << '\n';

	system("pause");
}
int priority(char a) {
	switch (a) {
	case '*':
	case '/': return 3;

	case '-':
	case '+': return 2;

	case '(': return 1;
	}

	return 0;
}
Stack* inStack(Stack *p, char s) {
	Stack *t = new Stack;
	t->c = s;
	t->next = p;
	return t;
}
Stack* outStack(Stack *p, char *s) {
	Stack *t = p;
	*s = p->c;
	p = p->next;
	delete t;
	return p;
}
double result(char* str) {
	char ch, ch1, ch2, chr;
	double op1, op2, rez;

	chr = 'z' + 1;
	for (int i = 0; i <= strlen(str); i++) {
		ch = str[i];
		if (!(ch == '+' || ch == '-' || ch == '*' || ch == '/')) {
			op = inStack(op, ch);
		}
		else {
			op = outStack(op, &ch1);
			op = outStack(op, &ch2);

			op1 = arr[int (ch1)];//
			op2 = arr[int (ch2)];//

			switch (ch)
			{
			case '+': rez = op2 + op1; break;
			case '-': rez = op2 - op1; break;
			case '*': rez = op2 * op1; break;
			case '/': rez = op2 / op1; break;
			case '^': rez = pow(op2, op1); break;
			}
			arr[int(chr)] = rez;//
			op = inStack(op, chr);
			chr++;
		}
	}
	return rez;
}
double readDoubleNum() {
	while (1) {
		double num;
		cin >> num;
		if (cin.get() == '\n') {
			return num;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << " Error 1: Value should be type double.\n ";
		}
	}
}