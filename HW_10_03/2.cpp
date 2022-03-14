//14. Даны целые числа a1, a2, ..., an, среди которых могут быть повторяющиеся.
//Составить новый массив из чисел, взятых по одному из каждой группы равных 
//членов данной последовательности.

#include <iostream>

using namespace std;

void mass_input(int* mass, int size);
void mass_output(int* mass, int size);
void vozr_pol(int* x, int n);
void ubyv_otr(int* x, int n);
int min_a(int* x, int n);
int max_a(int* x, int n);
int pn(int* x, int n, int b);
void prog1(int* x, int n);
void ubyv(int* x, int n);
void vozr(int* x, int n);
void prog2(int* x, int n);

int main() {
	setlocale(LC_ALL, "rus");
	const int size = 6;
	int mass[size];

	cout << "Введите значения массива:" << endl;
	mass_input(mass, size);
	prog2(mass, size);
	mass_output(mass, size);

	return 0;
}

void vozr(int* x, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		int m = min_a(&x[j], n - j);
		int imin = pn(&x[j], n - j, m);
		//cout<<m<<" "<<imin<<endl;
		int c = x[j];
		x[j] = x[j + imin];
		x[j + imin] = c;
	}
}

int pn(int* x, int n, int b)
{
	int p = -1;
	for (int i = 0; i < n; i++)
		if (x[i] == b)
		{
			p = i; break;
		}
	return p;
}

int max_a(int* x, int n)
{
	int m = x[0];
	for (int i = 0; i < n; i++)
		if (x[i] > m) m = x[i];
	return m;
}

int min_a(int* x, int n)
{
	int m = x[0];
	for (int i = 0; i < n; i++)
		if (x[i] < m) m = x[i];
	return m;
}

void mass_input(int* mass, int size) {
	for (int i = 0; i < size; i++) {
		cin >> mass[i];
	}
}

void mass_output(int* mass, int size) {
	for (int i = 0; i < size; i++) {
		if (mass[i] != 0) {
			cout << mass[i] << " ";
		}
	}
	cout << endl;
}

void vozr_pol(int* x, int n) {
	int j = 0;
	while (j < n - 1) {
		while ((x[j] <= 0) && (j < n - 1)) j++;
		if (j < n - 1) {
			int m = x[j];
			for (int i = j; i < n; i++)
				if ((x[i] > 0) && (x[i] < m)) m = x[i];
			int imin = pn(&x[j], n - j, m);
			int c = x[j];
			x[j] = x[j + imin];
			x[j + imin] = c;
		}
		j++;
	}
}

void ubyv_otr(int* x, int n) {
	int j = 0;
	while (j < n - 1) {
		while ((x[j] >= 0) && (j > n - 1)) j++;
		if (j < n - 1) {
			int m = x[j];
			for (int i = j; i < n; i++)
				if ((x[i] < 0) && (x[i] > m)) m = x[i];
			int imin = pn(&x[j], n - j, m);
			int c = x[j];
			x[j] = x[j + imin];
			x[j + imin] = c;
		}
		j++;
	}
}

void ubyv(int* x, int n) {
	for (int j = 0; j < n - 1; j++)
	{
		int m = max_a(&x[j], n - j);
		int imax = pn(&x[j], n - j, m);
		//cout<<m<<" "<<imin<<endl;
		int c = x[j];
		x[j] = x[j + imax];
		x[j + imax] = c;
	}
}

void prog1(int* x, int n) {
	vozr(x, n / 2);
	ubyv(&x[n / 2], n);
}

void prog2(int* x, int n) {
	int j = 0;
	while (j < n - 1) {
		if (x[j] > 0) {
			int m = x[j];
			for (int i = j; i < n; i++)
				if ((x[i] > 0) && (x[i] > m)) m = x[i];
			int imin = pn(&x[j], n - j, m);
			int c = x[j];
			x[j] = x[j + imin];
			x[j + imin] = c;
		}
		else {
			int m = x[j];
			for (int i = j; i < n; i++)
				if ((x[i] < 0) && (x[i] < m)) m = x[i];
			int imin = pn(&x[j], n - j, m);
			int c = x[j];
			x[j] = x[j + imin];
			x[j + imin] = c;
		}
		j++;
	}
}