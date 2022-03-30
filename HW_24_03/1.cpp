#include <iostream>
#include <random>

using namespace std;

void vvod(int** a, int n, int m);
void vvod2(int** a, int n, int m);
void vivod(int** a, int n, int m);
void matrix(int** a, int n, int m);
void pn(int** a, int n, int m, int elem, int& i1, int& j1);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));

	const int n = 5, m = 6;
	//выделение памяти
	int** a = new int* [n];
	for (int i = 0; i < n; i++) a[i] = new int[m];

	vvod2(a, n, m);
	vivod(a, n, m);
	matrix(a, n, m);

	//освобождение памяти
	for (int i = 0; i < n; i++) delete[]a[i];
	delete a;

	return 0;
}

void vvod2(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = rand() % 10;
}
void vvod(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
}
void vivod(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void pn(int** a, int n, int m, int elem, int& i1, int& j1)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == elem)
			{
				i1 = i;
				j1 = j;
				break;
			}
}

void matrix(int** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		int ma1, ma2, mi1, mi2, max = a[0][0], min = a[0][0];
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
			if (a[i][j] > max) {
				max = a[i][j];
				pn(a, i + 1, j + 1, max, ma1, ma2);
			}
			if (a[i][j] < min) {
				min = a[i][j];
				pn(a, i + 1, j + 1, min, mi1, mi2);
			}

		}
		cout << "Max:" << max << " #[" << ma1 << "][" << ma2 << "]";
		cout << " Min:" << min << " #[" << mi1 << "][" << mi2 << "]";
		cout << endl;
	}
}