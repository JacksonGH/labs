#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>
using namespace std;

/*
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	for (int i = 0; i < 25; i++) {//������� ��������� �� ��������� � ��������� �����
		int a = 1, b = 999, num = rand() % (b - a + 1) + a;
		cout << num << "  ";
		switch (num / 100) {
		case 1:cout << "��� "; break;
		case 2:cout << "������ "; break;
		case 3:cout << "������ "; break;
		case 4:cout << "��������� "; break;
		case 5:cout << "������� "; break;
		case 6:cout << "�������� "; break;
		case 7:cout << "������� "; break;
		case 8:cout << "��������� "; break;
		case 9:cout << "��������� "; break;
		}

		if (num / 10 % 10 != 1) {
			switch (num / 10 % 10) {
			case 2:cout << "�������� "; break;
			case 3:cout << "�������� "; break;
			case 4:cout << "����� "; break;
			case 5:cout << "��������� "; break;
			case 6:cout << "���������� "; break;
			case 7:cout << "��������� "; break;
			case 8:cout << "����������� "; break;
			case 9:cout << "��������� "; break;
			}
			switch (num % 10) {
			case 1:cout << "����"; break;
			case 2:cout << "���"; break;
			case 3:cout << "���"; break;
			case 4:cout << "������"; break;
			case 5:cout << "����"; break;
			case 6:cout << "�����"; break;
			case 7:cout << "����"; break;
			case 8:cout << "������"; break;
			case 9:cout << "������"; break;
			}
		}
		else {
			switch (num % 10) {
			case 1:cout << "�����������"; break;
			case 2:cout << "����������"; break;
			case 3:cout << "����������"; break;
			case 4:cout << "������������"; break;
			case 5:cout << "����������"; break;
			case 6:cout << "�����������"; break;
			case 7:cout << "����������"; break;
			case 8:cout << "������������"; break;
			case 9:cout << "������������"; break;
			}
		}
		cout << endl;
	}
	//2
	int a = 6, *pointer = &a;
	cout << &a << "\n" << pointer << "\n" << a << "\n" << *pointer << "\n";
	//3
	string myVariable = "Hello", userVariable;
	cin >> userVariable;//getline(cin,userVariable);
	cout << ((myVariable == userVariable) ? "genius" : "idiot") << "\n";
	
	//4
	int num; // ������ �������
	cout << "Enter integer value: ";
	cin >> num; // ��������� �� ������������ ������� �������
	srand(time(NULL));

	int *p_darr = new int[num]; // ��������� ������ ��� �������
	for (int i = 0; i < num; i++) {
		// ���������� ������� � ����� �������� ��� ���������
		p_darr[i] = rand()%10+1;
		cout << "Value of " << i << " element is " << p_darr[i] << endl;
	}
	delete[] p_darr; // ������� ������

	system("pause");
	return;
}
*/

int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++) {
		// ������� ������ ���������� � �����
		cout << "Argument " << i << " : " << argv[i] << endl;
	}
	system("pause");
	return 0;
}