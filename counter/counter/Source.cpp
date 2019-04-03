#include <iostream>

using namespace std;

int main() {
	char str1[81];
	puts("Enter the first line:");
	gets_s(str1);
	const char *str2 = " ";

	int num = 1, num_word, i_word;
	cin >> num_word;

	for (int i = 0;; i++) {
		if (num == num_word) {
			i_word = i;
			break;
		}
		if (str1[i] == str2[0] && str1[i + 1] != str2[0]) ++num;
	}
	//cout << "need word is - ";
	for (int i = i_word; str1[i] != str2[0] && i < strlen(str1); i++) {
		cout << str1[i];
	}
	cout << "\n";

	system("pause");
	return 0;
}