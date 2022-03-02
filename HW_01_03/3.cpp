#include <iostream>

using namespace std;

void mass_input(int* mass, int size); // Вводим массив
void mass_output(int* mass, int size); // Выводи массив
int max1(int* mass, int size); // Поиск максимального числа в массиве
int min1(int* mass, int size); // Поиск минимального числа в массиве
int max2(int* mass, int size); // Поиск 2-го максимума в массиве
int min2(int* mass, int size); // Поиск 2-го минимума в массиве
int max_o(int* mass, int size); // Поиск максимального отрицательного числа
int min_p(int* mass, int size); // Поиск минимального положительного числа
int max3(int* mass, int size); // Поиск 3-го максимума в массиве
int min3(int* mass, int size); // Поиск 3-го минимума в массиве
void sdvig_vlevo(int* mass, int size); // Свид массива влево
int pn(int* mass, int size, int poz); // Позиция заданного значения в массиве
void sdvigMaxMin(int* mass, int size, int start, int finish); // Сдвиг влево в заданном интервале

int main() {
	setlocale(LC_ALL, "rus");
	const int size = 17;
	int mass[size];

	mass_input(mass, size);
	cout << min3(mass, size) << endl;

	return 0;
}

void mass_input(int* mass, int size) {
	for (int i = 0; i < size; i++) {
		cin >> mass[i];
	}
}

void mass_output(int* mass, int size) {
	for (int i = 0; i < size; i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
}

int min1(int* mass, int size) {
	int min = mass[0];

	for (int i = 0; i < size; i++) {
		if (mass[i] < min) {
			min = mass[i];
		}
	}
	return min;
}

int max1(int* mass, int size) {
	int max = mass[0];

	for (int i = 0; i < size; i++) {
		if (mass[i] > max) {
			max = mass[i];
		}
	}
	return max;
}

int max2(int* mass, int size) {
	int j = 0;
	int max_elem = max1(mass, size);
	while (mass[j] == max_elem) j++;
	int max_elem2 = mass[j];
	for (int i = j; i < size; i++)
		if ((mass[i] > max_elem2) && (mass[i] < max_elem)) max_elem2 = mass[i];
	return max_elem2;
}

int min2(int* mass, int size) {
	int j = 0;
	int min_elem = min1(mass, size);
	while (mass[j] == min_elem) j++;
	int min_elem2 = mass[j];
	for (int i = j; i < size; i++)
		if ((mass[i] < min_elem2) && (mass[i] > min_elem)) min_elem2 = mass[i];
	return min_elem2;
}

int max_o(int* mass, int size) {
	int j = 0;
	while (mass[j] >= 0) j++;
	int max = mass[j];
	for (int i = j; i < size; i++)
		if ((mass[i] > max) && (mass[i] < 0)) max = mass[i];
	return max;
}

int min_p(int* mass, int size) {
	int j = 0;
	while (mass[j] <= 0) j++;
	int min = mass[j];
	for (int i = j; i < size; i++)
		if ((mass[i] < min) && (mass[i] > 0)) min = mass[i];
	return min;
}

int max3(int* mass, int size) {
	int j = 0;
	int max_elem = max1(mass, size);
	int max_elem2 = max2(mass, size);
	while (mass[j] == max_elem || mass[j] == max_elem2) j++;
	int max_elem3 = mass[j];
	for (int i = j; i < size; i++)
		if ((mass[i] > max_elem3) && (mass[i] < max_elem2)) max_elem3 = mass[i];
	return max_elem3;
}

int min3(int* mass, int size) {
	int j = 0;
	int min_elem = min1(mass, size);
	int min_elem2 = min2(mass, size);
	while (mass[j] == min_elem || mass[j] == min_elem2) j++;
	int min_elem3 = mass[j];
	for (int i = j; i < size; i++)
		if ((mass[i] < min_elem3) && (mass[i] > min_elem2)) min_elem3 = mass[i];
	return min_elem3;
}

void sdvig_vlevo(int* mass, int size) {
	int temp = mass[0];
	for (int i = 0; i < size - 1; i++) {
		mass[i] = mass[i + 1];
	}
	mass[size - 1] = temp;
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

void sdvigMaxMin(int* mass, int size, int start, int finish) {
	int znach = abs(start - finish);

	if (start > finish) {
		sdvig_vlevo(&mass[finish], znach + 1);
	}
	else {
		sdvig_vlevo(&mass[start], znach + 1);
	}
}