//4. В матрице А(nxn) определить количество строк,
//элементы которой образуют арифметическую прогрессию.
//Использовать подпрограмму проверки строки.

#include <iostream>
#include <ctime>

using namespace std;

void vvod(int** a, int n, int m);
void vivod(int** a, int n, int m);
bool arefm_str(int* a, int n);
int kol_vo(int** a, int n, int m);

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	const int n = 5;
	//выделение памяти
	int** a = new int* [n];
	for (int i = 0; i < n; i++) a[i] = new int[n];

	vvod(a, n, n);
	cout << kol_vo(a, n, n) << endl;

	//освобождение памяти
	for (int i = 0; i < n; i++) delete[]a[i];
	delete a;

	system("pause");
	return 0;
}

void vvod(int** a, int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
}
void vivod(int** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
bool arefm_str(int* mass, int n) {
	int d = mass[1] - mass[0];

	for (int i = 1; i < n - 1; i++) {
		if ((mass[i + 1] - mass[i]) != d) {
			return false;
		}
	}
	return true;
}
int kol_vo(int** a, int n, int m) {
	int s = 0;
	int* temp = new int[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[j] = a[i][j];
		}
		if (arefm_str(temp, n)) {
			s++;
		}
	}

	return s;
}