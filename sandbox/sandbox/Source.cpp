#include<iostream>
#include<math.h>
//#include<string>
//#include<cctype>
#include<sstream>//for 1st - not func
#include <iomanip>
#include <stdio.h>
using namespace std;

/*double checkNum(string s) {

	stringstream ss;
	ss << s;

	float num = 0;

	ss >> num;

	if (ss.good()) {
		return 0;
	}
	else if (num == 0 && s[0] != '0') {
		return 0;
	}
	else {
		return 1;
	}
}
double convertNum(string s) {

	stringstream ss;
	ss << s;

	float num = 0;

	ss >> num;

	if (ss.good()) {
		return 0;
	}
	else if (num == 0 && s[0] != '0') {
		return 0;
	}
	else {
		return num;
	}
}*/

int main()
{
	setlocale(LC_ALL, "rus");


	//частично решает проблему проверки(4 f; 4 4)
	//макс длинна 6
	/*string s;

	cin >> s;

	stringstream ss;
	ss << s;

	float num = 0;

	ss >> num;

	if (ss.good()) {
		cerr << "No Valid Number 1" << endl;
	}
	else if (num == 0 && s[0] != '0') {
		cerr << "No Valid Number 2" << endl;
	}
	else {
		cout << num << endl;
	}*/

	//string b = "0";
	//if (checkNum(b)) cout << convertNum(b)-1 << endl;
	//else cout << "Error" << endl;

	//cout<<isParam("2");


	double num;
	scanf("%lf", &num);
	

	system("pause");
	//http://ci-plus-plus-snachala.ru/?p=1516
}