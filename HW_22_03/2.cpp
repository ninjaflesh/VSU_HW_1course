#include <iostream>
#include <random>

using namespace std;

void vvod(int** a, int n, int m);
void vvod2(int** a, int n, int m);
void vivod(int** a, int n, int m);
void pr_str(int** a, int n, int m);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));

	const int n = 5, m = 6;
	//выделение памяти
	int** a = new int* [n];
	for (int i = 0; i < n; i++) a[i] = new int[m];

	vvod2(a, n, m);
	vivod(a, n, m);
	pr_str(a, n, m);

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
void pr_str(int** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		int pr = 1;
		for (int j = 0; j < m; j++) {
			pr *= a[i][j];
		}
		cout << "Произведение элем. строки = " << pr << endl;
	}
}
