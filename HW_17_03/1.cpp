#include <iostream>
#include <random>

using namespace std;

void vvod(char* str);
void vivod(char* str);
void password(char* str);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	const int size = 100;
	char mass[size];

	password(mass);
	vivod(mass);

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

void password(char* str) {
	int n = 0;
	cout << "Укажите размер пароля: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		switch (rand() % 3) {
		case 0:
			str[i] = char('A' + rand() % 26);
			break;
		case 1:
			str[i] = char('a' + rand() % 26);
			break;
		case 2:
			str[i] = char('0' + rand() % 10);
			break;
		}
	}
	str[n] = '\0';
}