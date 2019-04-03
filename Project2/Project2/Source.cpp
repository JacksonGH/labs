#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void main() {
	setlocale(LC_ALL, "rus");

	int a, b;
	cout << "Введите a и b" << endl;
	cin >> a >> b;
	int i = 0, num = rand() % (b - a + 1) + a, num1;
	srand(time(NULL));


	cout << "Task 1" << endl;
	do {
		cout << "Введите число ";
		cin >> num1;
		i++;
		if ((num1 >= a) && (num1 <= b)) {
			if (num == num1) {
				cout << "Ты угадал c " << i << " попытки"<<endl;
				break;
			};
			cout<< ((num1 < num) ? "Больше" : "Меньше")<<endl;
		}
		else cout << "Неверный диапазон значений"<< endl;
	} while (num != num1);


	cout << "Task 2" << endl;
	int smth = 0, protNum1 = num;
	do {
		smth += protNum1 % 10;
		protNum1 = protNum1 / 10;
	} while (protNum1 >= 1);
	cout << "Number is " << num << ". Sum is " << smth << endl;


	cout << "Task 3" << endl;
	int fact = num, protNum = num;
	while (--protNum) {//сделать для любых значений
		fact *= protNum;
	}
	cout << "Fact is " << fact << endl;


	cout << "Task 4" << endl;
	bool flag = true;
	int j = 2;
	while (j <= num/2) {// не подойдет (sqrt((double)num))
		if (!(num%j)) {
			flag = false;
			cout << j << " ";
		}
		j++;
	}
	cout << ((flag) ? "Простое" : "Составное") << endl;

	system("pause");
}