#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>
using namespace std;

/*
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	for (int i = 0; i < 25; i++) {//сделать изменение на заглавные и прописные буквы
		int a = 1, b = 999, num = rand() % (b - a + 1) + a;
		cout << num << "  ";
		switch (num / 100) {
		case 1:cout << "Сто "; break;
		case 2:cout << "Двести "; break;
		case 3:cout << "Триста "; break;
		case 4:cout << "Четыреста "; break;
		case 5:cout << "Пятьсот "; break;
		case 6:cout << "Шестьсот "; break;
		case 7:cout << "Семьсот "; break;
		case 8:cout << "Восемьсот "; break;
		case 9:cout << "Девятьсот "; break;
		}

		if (num / 10 % 10 != 1) {
			switch (num / 10 % 10) {
			case 2:cout << "Двадцать "; break;
			case 3:cout << "Тридцать "; break;
			case 4:cout << "Сорок "; break;
			case 5:cout << "Пятьдесят "; break;
			case 6:cout << "Шестьдесят "; break;
			case 7:cout << "Семьдесят "; break;
			case 8:cout << "Восемьдесят "; break;
			case 9:cout << "Девяносто "; break;
			}
			switch (num % 10) {
			case 1:cout << "Один"; break;
			case 2:cout << "Два"; break;
			case 3:cout << "Три"; break;
			case 4:cout << "Четыре"; break;
			case 5:cout << "Пять"; break;
			case 6:cout << "Шесть"; break;
			case 7:cout << "Семь"; break;
			case 8:cout << "Восемь"; break;
			case 9:cout << "Девять"; break;
			}
		}
		else {
			switch (num % 10) {
			case 1:cout << "Одиннадцать"; break;
			case 2:cout << "Двенадцать"; break;
			case 3:cout << "Тринадцать"; break;
			case 4:cout << "Четырнадцать"; break;
			case 5:cout << "Пятнадцать"; break;
			case 6:cout << "Шестнадцать"; break;
			case 7:cout << "Семнадцать"; break;
			case 8:cout << "Восемнадцать"; break;
			case 9:cout << "Девятнадцать"; break;
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
	int num; // размер массива
	cout << "Enter integer value: ";
	cin >> num; // получение от пользователя размера массива
	srand(time(NULL));

	int *p_darr = new int[num]; // Выделение памяти для массива
	for (int i = 0; i < num; i++) {
		// Заполнение массива и вывод значений его элементов
		p_darr[i] = rand()%10+1;
		cout << "Value of " << i << " element is " << p_darr[i] << endl;
	}
	delete[] p_darr; // очистка памяти

	system("pause");
	return;
}
*/

int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++) {
		// Выводим список аргументов в цикле
		cout << "Argument " << i << " : " << argv[i] << endl;
	}
	system("pause");
	return 0;
}