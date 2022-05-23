#include <iostream>
#include <windows.h>

using namespace std;

struct complex {
	double Re, Im;
};

char filename[100] = "d:\\file.dat";

void file_input(FILE* f);
void file_output(FILE* f);
void insert(FILE* f);
void append(FILE* f);
void max_complex(FILE* f);
void sort_re_vozr(FILE* f);
void sort_re_ubiv(FILE* f);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* f = nullptr;
	int rezhim;

	do {
		cout << "Выберите: \n0-EXIT, 1-Новый ввод, 2-Добавить, 3-Вывод" << endl;
		cout << "4-Макс. модуль, 5-Cортировка по возрастанию, 6-Cортировка по убыванию" << endl;
		cin >> rezhim;
		switch (rezhim) {
		case 1:file_input(f); break;
		case 2:append(f); break;
		case 3:file_output(f); break;
		case 4:max_complex(f); break;
		case 5:sort_re_vozr(f); break;
		case 6:sort_re_ubiv(f); break;
		}
	} while (rezhim);

	system("pause");
	return 0;
}

void file_input(FILE* f) {
	fopen_s(&f, filename, "w");
	insert(f);
}
void file_output(FILE* f) {
	fopen_s(&f, filename, "r");
	complex dat;
	while (fread(&dat, sizeof(dat), 1, f)) {
		cout << dat.Re << "+" << dat.Im << "i" << endl;
	}
	fclose(f);
}
void insert(FILE* f) {
	int n;
	complex dat;
	cout << "Введите количество чисел: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Введите число: ";
		cin >> dat.Re >> dat.Im;
		fwrite(&dat, sizeof(dat), 1, f);
	}
	fclose(f);
}
void append(FILE* f) {
	fopen_s(&f, filename, "a");
	insert(f);
}
void max_complex(FILE* f) {
	fopen_s(&f, filename, "r");

	fseek(f, 0, SEEK_END);
	long lSize = ftell(f);
	rewind(f);

	complex dat;
	int n = 0;
	complex* temp = new complex[lSize];

	while (fread(&dat, sizeof(dat), 1, f)) {
		temp[n] = dat;
		n++;
	}
	complex max_c = temp[0];
	for (int i = 0; i < n; i++) {
		if (temp[i].Re > max_c.Re && temp[i].Im > max_c.Im) {
			max_c = temp[i];
		}
	}
	cout << max_c.Re << "+" << max_c.Im << "i" << endl;

	fclose(f);
}
void sort_re_vozr(FILE* f) {
	fopen_s(&f, filename, "r");

	fseek(f, 0, SEEK_END);
	long lSize = ftell(f);
	rewind(f);

	complex dat;
	int n = 0;
	complex* temp = new complex[lSize];

	while (fread(&dat, sizeof(dat), 1, f)) {
		temp[n] = dat;
		n++;
	}

	int min_s, imin;
	complex min_c;
	for (int i = 0; i < n - 1; i++){
		min_s = temp[i].Re;
		imin = i;
		for (int j = i; j < n; j++) {
			if (temp[j].Re < min_s) {
				min_s = temp[j].Re;
				imin = j;
			}
		}
		min_c = temp[i];
		temp[i] = temp[imin];
		temp[imin] = min_c;
	}

	for (int i = 0; i < n; i++) {
		cout << temp[i].Re << "+" << temp[i].Im << "i" << endl;
	}

	fclose(f);
}
void sort_re_ubiv(FILE* f) {
	fopen_s(&f, filename, "r");

	fseek(f, 0, SEEK_END);
	long lSize = ftell(f);
	rewind(f);

	complex dat;
	int n = 0;
	complex* temp = new complex[lSize];

	while (fread(&dat, sizeof(dat), 1, f)) {
		temp[n] = dat;
		n++;
	}

	int max_s, imin;
	complex min_c;
	for (int i = 0; i < n - 1; i++) {
		max_s = temp[i].Re;
		imin = i;
		for (int j = i; j < n; j++) {
			if (temp[j].Re > max_s) {
				max_s = temp[j].Re;
				imin = j;
			}
		}
		min_c = temp[i];
		temp[i] = temp[imin];
		temp[imin] = min_c;
	}

	for (int i = 0; i < n; i++) {
		cout << temp[i].Re << "+" << temp[i].Im << "i" << endl;
	}

	fclose(f);
}
