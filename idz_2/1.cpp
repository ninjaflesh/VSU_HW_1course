//14. Дана строка. Напечатать те слова этой строки,
//которые отличны от последнего слова и выполнено свойство:
//cлово совпадает с конечным отрезком латинского алфавита(z, yz, xyz и т.д.).

#include <iostream> 

using namespace std;

void input_str(char* str);
void output_str(char* str);
void last_word(char* str, char* word);
void different_words(char* str);

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	const int size = 100;
	char mass[size];

	input_str(mass);
	different_words(mass);

	system("pause");
	return 0;
}

void input_str(char* str) {
	gets_s(str, 100);
}
void output_str(char* str) {
	cout << str << endl;
}
void last_word(char* str, char* word) {
	int i = strlen(str) - 1;
	while ((str[i] == ' ') && (i >= 0)) {
		i--;
	};
	while ((str[i] != ' ') && (i >= 0)) {
		i--;
	}
	i++;
	int j = 0;
	while ((str[i] != ' ') && (i < strlen(str))) {
		word[j++] = str[i++];
	}
	word[j] = '\0';
}
void different_words(char* str) {
	char alphabet[27] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0' };

	char lst_word[100];
	last_word(str, lst_word);

	int s = 0, i = 0;
	char str2[100];
	while (i < strlen(str)) {
		while ((str[i] == ' ') && (i < strlen(str))) {
			i++;
		}
		int j = 0;
		while ((str[i] != ' ') && (i < strlen(str))) {
			if ((str[i] != lst_word[j]) && (str[i] == alphabet[strlen(alphabet) - j - 1])) {
				str2[s] = str[i];
				s++;
			}
			i++;
			j++;
		}
		if (str2[s - 1] != ' ') {
			str2[s++] = ' ';
		}
	}
	str2[s] = '\0';
	output_str(str2);
}