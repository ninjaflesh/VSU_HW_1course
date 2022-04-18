#include <iostream> 

using namespace std;

void output_m(int** mass, int n);
void input_m(int** mass, int n);
int pn(int* mass, int size, int poz);
int min_a(int* mass, int size);
int max_a(int* mass, int size);
void max_matrix(int** a, int n);
void min_matrix(int** a, int n);
void upor_matrix(int** a, int n);
void vozr(int* x, int n);
void ubyv(int* arr, int N);
void upor_matrix_stolbec(int** a, int n);

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	const int n = 5;
	//выделение памяти 
	int** a = new int* [n];

	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}

	input_m(a, n);
	output_m(a, n);
	upor_matrix_stolbec(a, n);
	cout << endl;
	output_m(a, n);

	//освобождение памяти 
	for (int i = 0; i < n; i++) {
		delete[]a[i];
	}
	delete a;

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
			mass[i][j] = rand() % 10;
		}
	}
}
int min_a(int* mass, int size) {
	int min = mass[0];

	for (int i = 0; i < size; i++) {
		if (mass[i] < min) {
			min = mass[i];
		}
	}
	return min;
}
int max_a(int* mass, int size) {
	int max = mass[0];

	for (int i = 0; i < size; i++) {
		if (mass[i] > max) {
			max = mass[i];
		}
	}
	return max;
}
int pn(int* mass, int size, int poz) {
	int num = -1;
	for (int i = 0; i < size; i++) {
		if (mass[i] == poz) {
			num = i; break;
		}
	}
	return num;
}
void max_matrix(int** a, int n) {
	for (int i = 0; i < n; i++) {
		int m = max_a(a[i], n);
		cout << "Max: " << m << " ";
		cout << "Poz: " << pn(a[i], n, m) << endl;
	}
}
void min_matrix(int** a, int n) {
	for (int i = 0; i < n; i++) {
		int m = min_a(a[i], n);
		cout << "Min: " << m << " ";
		cout << "Poz: " << pn(a[i], n, m) << endl;
	}
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
void ubyv(int* arr, int N)
{
	for (int j = 0; j < N - 1; j++)
	{
		int m = max_a(&arr[j], N - j);
		int imax = pn(&arr[j], N - j, m);
		//cout<<m<<" "<<imin<<endl; 
		int c = arr[j];
		arr[j] = arr[j + imax];
		arr[j + imax] = c;
	}
}
void upor_matrix(int** a, int n) {
	for (int i = 0; i < n; i++) {
		if (i % 2) {
			vozr(a[i], n);
		}
		else {
			ubyv(a[i], n);
		}
	}
}
void upor_matrix_stolbec(int** a, int n) {
	int* tmp = new int[n];
	for (int j = 0; j < n; j++){
		for (int i = 0; i < n; i++) {
			tmp[i] = a[i][j];
		}

		if (j % 2) {
			vozr(tmp, n);
		}
		else {
			ubyv(tmp, n);
		}

		for (int i = 0; i < n; i++) {
			a[i][j] = tmp[i];
		}
	}
	delete tmp;
}