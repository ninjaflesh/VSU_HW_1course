#include <iostream>

using namespace std;

void vvod(char* str);
void vivod(char* str);
void palendrom(char* str);

int main() {
	setlocale(LC_ALL, "rus");
	const int size = 100;
	char mass[size];

	vvod(mass);
	palendrom(mass);

	return 0;
}

void vvod(char* str)
{
	gets_s(str, 100);
}

void vivod(char* str)
{
	cout << str << endl;
}

void palendrom(char* str) {
	int j;
	char str2[100];
	for (int i = 0; i < strlen(str); i++) {
		while ((str[i] == ' ') && (i < strlen(str))) {
			i++;
		}

		j = 0;

		while ((str[i] != ' ') && (i < strlen(str))) {
			str2[j++] = str[i++];
		}
		str2[j] = '\0';

		bool flag = true;
		for (int k = 0; k < strlen(str2) / 2; k++) {
			if (str2[k] != str2[strlen(str2) - k - 1]) {
				flag = false;
			}
		}

		if (!flag) {
			cout << "Не полиндром ";
			vivod(str2);
		}
		else {
			cout << "Полиндром ";
			vivod(str2);
		}
	}
}