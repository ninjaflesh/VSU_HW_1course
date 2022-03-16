#include <iostream>

using namespace std;

void vvod(char* str);
void vivod(char* str);
int kolvo_chisel(char* str);

int main() {
	setlocale(LC_ALL, "rus");
	const int size = 100;
	char mass[size];

	vvod(mass);
	cout << kolvo_chisel(mass) << endl;

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
int kolvo_chisel(char* str) {
	int i = 0;
	int chislo = 0;
	while (i < strlen(str)) {
		while ((str[i] == ' ') && (i < strlen(str))) {
			i++;
		}
		while ((str[i] != ' ') && (i < strlen(str))) {
			if ((str[i] == '0') || (str[i] == '1') ||
				(str[i] == '2') || (str[i] == '3') ||
				(str[i] == '4') || (str[i] == '5') ||
				(str[i] == '6') || (str[i] == '7') ||
				(str[i] == '8') || (str[i] == '9')) {
				chislo++;
			}
			i++;
		}
	}
	return chislo;
}