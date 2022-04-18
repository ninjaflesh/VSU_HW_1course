//14. Даны целые числа a1, a2, ..., an, среди которых могут быть повторяющиеся.
//Составить новый массив из чисел, взятых по одному из каждой группы равных 
//членов данной последовательности.

#include <iostream>

using namespace std;

void mass_input(int* mas, int size);
void mass_output(int* mas, int size);
int min_a(int* mas, int size);
int pn(int* mas, int size, int poz);
void sort(int* mas, int size);
void filt(int* mas, int* s_mas, int size);
int size_m(int* mas, int size);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int size = 6;
	int* mas = new int[size];

	cout << "Введите значения массива:" << endl;
	mass_input(mas, size);
	sort(mas, size);
	int new_size = size_m(mas, size);
	int* s_mas = new int[new_size];
	filt(mas, s_mas, size);
	mass_output(s_mas, new_size);

	return 0;
}

void mass_input(int* mas, int size) {
	for (int i = 0; i < size; i++) {
		cin >> mas[i];
	}
}
void mass_output(int* mas, int size) {
	for (int i = 0; i < size; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;
}
int min_a(int* mas, int size) {
	int min = mas[0];

	for (int i = 0; i < size; i++) {
		if (mas[i] < min) {
			min = mas[i];
		}
	}
	return min;
}
int pn(int* mas, int size, int poz) {
	int num = -1;
	for (int i = 0; i < size; i++) {
		if (mas[i] == poz) {
			num = i; break;
		}
	}
	return num;
}
void sort(int* mas, int size) {
	for (int j = 0; j < size - 1; j++) {
		int m = min_a(&mas[j], size - j);
		int imin = pn(&mas[j], size - j, m);
		//cout<<m<<" "<<imin<<endl; 
		int c = mas[j];
		mas[j] = mas[j + imin];
		mas[j + imin] = c;
	}
}
void filt(int* mas, int* s_mas, int size) {
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (mas[i] == mas[i + 1] && mas[i] != mas[i - 1]) {
			s_mas[j] = mas[i];
			j++;
		}
	}
}
int size_m(int* mas, int size) {
	int s = 0;
	for (int i = 0; i < size; i++) {
		if (mas[i] == mas[i + 1] && mas[i] != mas[i - 1]) {
			s++;
		}
	}
	return s;
}