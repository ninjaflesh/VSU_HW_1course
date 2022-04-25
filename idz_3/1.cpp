#include <iostream> 

using namespace std;

void input_m(int** mass, int size);
void output_m(int** mass, int size);
void num1(int** mass, int n, int m);
void num2(int** mass, int n, int m);
void num3(int** mass, int n, int m);
void num4(int** mass, int n, int m);
void num5(int** mass, int n, int m);
void num6(int** mass, int n, int m);
void num7(int** mass, int n, int m);

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	const int n = 6;
	//выделение памяти 
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}

	input_m(a, n);
	cout << "Исходная матрица:" << endl;
	output_m(a, n);
	cout << endl;

	num1(a, n, n); cout << endl;
	num2(a, n, n); cout << endl;
	num3(a, n, n); cout << endl;
	num4(a, n, n); cout << endl;
	num5(a, n, n); cout << endl;
	num6(a, n, n); cout << endl;
	num7(a, n, n); cout << endl;

	// освобождение памяти
	for (int i = 0; i < n; i++) {
		delete[]a[i];
	}
	delete a;

	system("pause");
	return 0;
}

void input_m(int** mass, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mass[i][j] = rand() % 10;
		}
	}
}
void output_m(int** mass, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mass[i][j] << " ";
		}
		cout << endl;
	}
}
void num1(int** mass, int n, int m) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (!flag) {
			for (int j = 0; j < m; j++) {
				cout << mass[j][i];
			}
			flag = true;
		}
		else {
			for (int g = m - 1; g >= 0; g--) {
				cout << mass[g][i];
			}
			flag = false;
		}
	}
}
void num2(int** mass, int n, int m) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (!flag) {
			for (int j = 0; j < m; j++) {
				cout << mass[i][j];
			}
			flag = true;
		}
		else {
			for (int g = m - 1; g >= 0; g--) {
				cout << mass[i][g];
			}
			flag = false;
		}
	}
}
void num3(int** mass, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j >= i) {
				cout << mass[i][j];
			}
		}
	}
}
void num4(int** mass, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j <= i) {
				cout << mass[i][j];
			}
		}
	}
}
void num5(int** mass, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j <= m - i - 1) {
				cout << mass[i][j];
			}
		}
	}
}
void num6(int** mass, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j >= m - i - 1) {
				cout << mass[i][j];
			}
		}
	}
}
void num7(int** mass, int n, int m) {
	int i = 1, j, k;
	int	p = n / 2;
	for (k = 1; k <= p; k++) {
		for (j = k - 1; j < n - k + 1; j++) cout << mass[k - 1][j];
		for (j = k; j < n - k + 1; j++) cout << mass[j][n - k];
		for (j = n - k - 1; j >= k - 1; --j) cout << mass[n - k][j];
		for (j = n - k - 1; j >= k; j--) cout << mass[j][k - 1];
	}
}