void mass_rand_input(int* mass, int size) {
	for (int i = 0; i < size; i++) {
		mass[i] = rand() % 100;
	}
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

bool levo_pravo(int* mass, int size) {
	for (int i = 0; i < size / 2; i++) {
		if (mass[i] != mass[size - i - 1]) {
			return false;
		}
		return true;
	}
}

bool upor_vozr(int* mass, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (mass[i] > mass[i + 1]) {
			return false;
		}
	}
	return true;
}

bool upor_ubiv(int* mass, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (mass[i] < mass[i + 1]) {
			return false;
		}
	}
	return true;
}

void sdvig_vlevo(int* mass, int size) {
	int temp = mass[0];
	for (int i = 0; i < size - 1; i++) {
		mass[i] = mass[i + 1];
	}
	mass[size - 1] = temp;
}

void sdvig_vpravo(int* mass, int size) {
	int temp = mass[size - 1];
	for (int i = size - 1; i > 0; i--) {
		mass[i] = mass[i - 1];
	}
	mass[0] = temp;
}

void sdvigMleft(int* mass, int size, int move) {
	while (move) {
		int temp = mass[0];
		for (int i = 0; i < size - 1; i++) {
			mass[i] = mass[i + 1];
		}
		mass[size - 1] = temp;
		move--;
	}
}

void sdvigMright(int* mass, int size, int move) {
	while (move) {
		int temp = mass[size - 1];
		for (int i = size - 1; i > 0; i--) {
			mass[i] = mass[i - 1];
		}
		mass[0] = temp;
		move--;
	}
}

void sdvig1000(int* mass, int size) {
	for (int i = 10; i <= size; i += 10) {
		int temp = mass[i - 10];
		for (int j = i - 10; j < i; j++) {
			mass[j] = mass[j + 1];
		}
		mass[i - 1] = temp;
	}
	cout << endl;
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

void sdvigMaxMin(int* mass, int size) {
	int max_poz = pn(mass, size, max_a(mass, size));
	int min_poz = pn(mass, size, min_a(mass, size));

	int znach = abs(max_poz - min_poz);
	if (znach > 2) {
		if (max_poz > min_poz) {
			sdvig_vlevo(&mass[min_poz], znach + 1);
		}
		else {
			sdvig_vlevo(&mass[max_poz], znach + 1);
		}
	}
	else {
		cout << "Интервал меньше 2-х элементов." << endl;
	}
}
