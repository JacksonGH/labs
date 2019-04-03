#include <iostream>

void func(float &a, float &b, float &c);
double question(float &a, float &b, float &c);

int main()
{
	setlocale(LC_ALL, "RUS");
	float a = 0, b = 0, c = 0;
	func(a, b, c);
	int i = question(a, b, c);
	std::cout << i<<"\n";
	//_getch();
	system("pause");
	return 0;
}

void func(float &a, float &b, float &c) {
	printf("a= ");
	scanf_s("%f", &a); // вводим a 
	printf("b= ");
	scanf_s("%f", &b); // вводим b 
	printf("c= ");
	scanf_s("%f", &c); // вводим c 
}

double question(float &a, float &b, float &c) {
	char answer;
	printf("Вы хотите это решить: %.2fx^2%+.2fx%+.2f = 0 ", a, b, c);
	scanf_s("%c", &answer);
	return answer;
	printf("%c", answer);
}