#include <iostream> 

using namespace std;

void output_m(int** mass, int n);
void input_m(int** mass, int n);
void minus_m(int** a, int** b, int n, int** c);
void plus_m(int** a, int** b, int n, int** c);
void koef(int** a, int n, int k, int** c);
bool ravno(int** a, int** b, int n);
void proizv(int** a, int** b, int n, int** c);
void stepen(int** a, int n, int st, int** c);
bool formula(int** a, int** b, int** c, int n);

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	const int n = 5;
	//выделение памяти 
	int** a = new int* [n];
	int** b = new int* [n];
	int** c = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		b[i] = new int[n];
		c[i] = new int[n];
	}

	input_m(a, n);
	cout << "Матрица А:" << endl;
	output_m(a, n);

	input_m(b, n);
	cout << "Матрица B:" << endl;
	output_m(b, n);

	input_m(c, n);
	cout << "Матрица C:" << endl;
	output_m(c, n);

	cout << formula(a, b, c, n) << endl;

	//освобождение памяти 
	for (int i = 0; i < n; i++) {
		delete[]a[i];
		delete[]b[i];
		delete[]c[i];
	}
	delete a;
	delete b;
	delete c;

	system("pause");
	return 0;
}

void output_m(int** mass, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mass[i][j] << " ";
		}
		cout << endl;
	}
}
void input_m(int** mass, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mass[i][j] = rand() % 10 + 1;
		}
	}
}
void minus_m(int** a, int** b, int n, int** c) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = a[i][j] - b[i][j];
}
void plus_m(int** a, int** b, int n, int** c) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = a[i][j] + b[i][j];
}
void koef(int** a, int n, int k, int** c) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = k * a[i][j];
}
bool ravno(int** a, int** b, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != b[i][j]) {
				return false;
			}
	return true;
}
void proizv(int** a, int** b, int n, int** c) {
	int s;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			s = 0;
			for (int p = 0; p < n; p++)
				s = s + a[i][p] * b[p][j];
			c[i][j] = s;
		}
}
void stepen(int** a, int n, int st, int** c) {
	int** m = new int* [n];
	for (int i = 0; i < n; i++) m[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			m[i][j] = a[i][j];

	for (int k = 0; k < st - 1; k++)
	{
		proizv(m, a, n, c);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				m[i][j] = c[i][j];
	}

	for (int i = 0; i < n; i++) delete[]m[i]; delete m;
}
bool formula(int** a, int** b, int** c, int n) {
	int** temp1 = new int* [n];
	int** temp2 = new int* [n];
	int** temp3 = new int* [n];
	int** temp4 = new int* [n];
	int** temp5 = new int* [n];
	int** temp6 = new int* [n];
	int** temp7 = new int* [n];
	for (int i = 0; i < n; i++) {
		temp1[i] = new int[n];
		temp2[i] = new int[n];
		temp3[i] = new int[n];
		temp4[i] = new int[n];
		temp5[i] = new int[n];
		temp6[i] = new int[n];
		temp7[i] = new int[n];
	}

	koef(a, n, 4, temp1);
	koef(b, n, 3, temp2);
	koef(c, n, -7, temp3);
	plus_m(temp1, temp2, n, temp4);
	plus_m(temp4, temp3, n, temp4);
	stepen(temp4, n, 2, temp7); // левая часть

	stepen(temp1, n, 2, temp5);
	stepen(temp2, n, 2, temp6);
	plus_m(temp5, temp6, n, temp5);
	stepen(temp3, n, 2, temp6);
	plus_m(temp5, temp6, n, temp5);
	proizv(temp1, temp2, n, temp6);
	plus_m(temp5, temp6, n, temp5);
	proizv(temp2, temp1, n, temp6);
	plus_m(temp5, temp6, n, temp5);
	proizv(temp1, temp3, n, temp6);
	plus_m(temp5, temp6, n, temp5);
	proizv(temp3, temp1, n, temp6);
	plus_m(temp5, temp6, n, temp5);
	proizv(temp2, temp3, n, temp6);
	plus_m(temp5, temp6, n, temp5);
	proizv(temp3, temp2, n, temp6);
	plus_m(temp5, temp6, n, temp5); // правая часть

	return ravno(temp7, temp5, n);
}