#include <iostream>
#include <windows.h>
#include <cstdio>
#include <string.h>

using namespace std;
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char stroka[81], slovo[81];
	cout << "Исходная строка: "<< endl;
	gets_s(stroka);
	cout<< "Длина строки: ";
	cout << strlen(stroka)<< endl;
	int len_stroka = strlen(stroka);
	int k = 0;
	cout << "Позиция: ";
	cin >> k;

	int n = 0;
	if (stroka[0] != ' ')
	{
		n = 1;
	}
	else
	{
		n = 0;
	}
	for (int i = 1; i <= len_stroka; i++)
	{
		if (stroka[i] == ' ' && stroka[i + 1] != ' ')
		{
			n++;
		}
	}
	cout << "Кол-во слов: " << n << endl;


	if (stroka[len_stroka - 1] != ' ')
	{
		strcat_s(stroka, " ");
		len_stroka++;
	}


	int s;
	for (k; stroka[k] != ' '; k--)
	{
		s = k;
	}
	cout << "Слово с k-той позицией: " << endl;
	for (s; stroka[s] != ' '; s++)
	{
		cout << stroka[s];
	}
	cout << endl;

	int posiсia = 1;
	for (int i = 0; i < k; i++)
		if (stroka[i] != ' ')
		{
		}
		else
		{
			posiсia++;
		}
	cout << "Порядковый номер слова с k-той позицией: " << posiсia << endl;

	system("pause");
}