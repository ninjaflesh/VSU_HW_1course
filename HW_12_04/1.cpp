#include <iostream>
#include <ctime>

using namespace std;

void vvod2(int** a, int n, int k);
void vivod(int** a, int n, int k);
void prem_proizv(int** a, int** b, int** c, int col1, int row1, int col2, int row2);

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	const int col1 = 4, row1 = 2, col2 = 3, row2 = 4;
	//выделение памяти
	int** a = new int* [col1];
	for (int i = 0; i < row1; i++) a[i] = new int[row1];
	int** b = new int* [col2];
	for (int i = 0; i < row2; i++) b[i] = new int[row2];
	int** c = new int* [col2];
	for (int i = 0; i < row1; i++) c[i] = new int[row1];

	vvod2(a, row1, col1);
	cout << "Матрица A" << endl; vivod(a, row1, col1);
	vvod2(b, row2, col2);
	cout << "Матрица B" << endl; vivod(b, row2, col2);
	prem_proizv(a, b, c, col1, row1, col2, row2);
	cout << "Матрица C" << endl; vivod(c, row1, col2);

	//освобождение памяти
	//for (int i = 0; i < k; i++) delete[]a[i]; delete a;
	//for (int i = 0; i < m; i++) delete[]b[i]; delete b;
	//for (int i = 0; i < m; i++) delete[]c[i]; delete c;

	system("pause");
	return 0;
}

void prem_proizv(int** a, int** b, int** c, int col1, int row1, int col2, int row2) {
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			c[i][j] = 0;
			for (int p = 0; p < col1; p++) {
				//cout << a[i][p] << " " << b[p][j]<<endl;
				c[i][j] += a[i][p] * b[p][j];
			}
		}
	}
}

void vvod2(int** a, int n, int k) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			a[i][j] = rand() % 10;
}
void vivod(int** a, int n, int k) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}