#include <iostream> 
#include <windows.h> 

using namespace std;

struct student {
	int id;
	char surname[20];
	char name[15];
	double avg;
	int age;
};

void input_studenta(student* user, int size);
void output_studenta(student* user, int size);
void max_avg(student* user, int size);
void increase_id(student* user, int size);
void increase_surname(student* user, int size);
void increase_avg(student* user, int size);
void increase_age(student* user, int size);
void decrease_id(student* user, int size);
void decrease_surname(student* user, int size);
void decrease_avg(student* user, int size);
void decrease_age(student* user, int size);
void max_len_surname(student* user, int size);
void swap_max_min(student* user, int size);

int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "Введите кол-во студентов: ";
	cin >> n;
	student* db = new student[n];

	input_studenta(db, n);
	swap_max_min(db, n);
	output_studenta(db, n);

	/*int rezhim;
	do {
		cout << "Выберите режим сортировки: \n[0]-EXIT\n";
		cout << "[11]-Фамилия [21]-Возраста [31]-Средний бал [41]-Код\n";
		cout << "[12]-Фамилия [22]-Возраст [32]-Средный бал [42]-Код\n";
		cin >> rezhim;
		switch (rezhim) {
		case 11:increase_surname(db, n); output_studenta(db, n); break;
		case 21:increase_age(db, n); output_studenta(db, n); break;
		case 31:increase_avg(db, n); output_studenta(db, n); break;
		case 41:increase_id(db, n); output_studenta(db, n); break;
		case 12:decrease_surname(db, n); output_studenta(db, n); break;
		case 22:decrease_age(db, n); output_studenta(db, n); break;
		case 32:decrease_avg(db, n); output_studenta(db, n); break;
		case 42:decrease_id(db, n); output_studenta(db, n); break;
		}
	} while (rezhim);*/

	delete db;

	system("pause");
	return 0;
}

void input_studenta(student* user, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Код: "; cin >> user[i].id;
		cout << "Имя: "; cin >> user[i].name;
		cout << "Фамилия: "; cin >> user[i].surname;
		cout << "Возраст: "; cin >> user[i].age;
		cout << "Ср. бал: "; cin >> user[i].avg;
		cout << endl;
	}
}
void output_studenta(student* user, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Код: " << user[i].id << endl;
		cout << "Имя: " << user[i].name << endl;
		cout << "Фамилия: " << user[i].surname << endl;
		cout << "Возраст: " << user[i].age << endl;
		cout << "Ср. бал: " << user[i].avg << endl;
		cout << endl;
	}
}
void max_avg(student* user, int size) {
	student maxavg = user[0];
	for (int i = 0; i < size; i++) {
		if (user[i].avg > maxavg.avg) {
			maxavg = user[i];
		}
	}
	cout << "Студент с макс. средним балом:" << endl;
	output_studenta(&maxavg, 1);
}
void increase_id(student* user, int size) {
	int min_id, imin;
	student temp;
	for (int i = 0; i < size - 1; i++) {
		min_id = user[i].id;
		imin = i;
		for (int j = i; j < size; j++)
			if (user[j].id < min_id) {
				min_id = user[j].id;
				imin = j;
			}
		temp = user[i];
		user[i] = user[imin];
		user[imin] = temp;
	}
}
void increase_surname(student* user, int size) {
	char min_fio[20];
	int imin;
	student temp;
	for (int i = 0; i < size - 1; i++) {
		strcpy_s(min_fio, user[i].surname);
		imin = i;
		for (int j = i; j < size; j++)
			if (strcmp(user[j].surname, min_fio) < 0) {
				strcpy_s(min_fio, user[j].surname);
				imin = j;
			}
		temp = user[i];
		user[i] = user[imin];
		user[imin] = temp;
	}
}
void increase_avg(student* user, int size) {
	int min_avg, imin;
	student temp;
	for (int i = 0; i < size - 1; i++) {
		min_avg = user[i].avg;
		imin = i;
		for (int j = i; j < size; j++)
			if (user[j].avg < min_avg) {
				min_avg = user[j].avg;
				imin = j;
			}
		temp = user[i];
		user[i] = user[imin];
		user[imin] = temp;
	}
}
void increase_age(student* user, int size) {
	int min_age, imin;
	student temp;
	for (int i = 0; i < size - 1; i++) {
		min_age = user[i].age;
		imin = i;
		for (int j = i; j < size; j++)
			if (user[j].age < min_age) {
				min_age = user[j].age;
				imin = j;
			}
		temp = user[i];
		user[i] = user[imin];
		user[imin] = temp;
	}
}
void decrease_id(student* user, int size) {
	int max_id, imax;
	student temp;
	for (int i = 0; i < size - 1; i++) {
		max_id = user[i].id;
		imax = i;
		for (int j = i; j < size; j++)
			if (user[j].id > max_id) {
				max_id = user[j].id;
				imax = j;
			}
		temp = user[i];
		user[i] = user[imax];
		user[imax] = temp;
	}
}
void decrease_surname(student* user, int size) {
	char max_fio[20];
	int imax;
	student temp;
	for (int i = 0; i < size - 1; i++) {
		strcpy_s(max_fio, user[i].surname);
		imax = i;
		for (int j = i; j < size; j++)
			if (strcmp(user[j].surname, max_fio) > 0) {
				strcpy_s(max_fio, user[j].surname);
				imax = j;
			}
		temp = user[i];
		user[i] = user[imax];
		user[imax] = temp;
	}
}
void decrease_avg(student* user, int size) {
	int max_avg, imax;
	student temp;
	for (int i = 0; i < size - 1; i++) {
		max_avg = user[i].avg;
		imax = i;
		for (int j = i; j < size; j++)
			if (user[j].avg > max_avg) {
				max_avg = user[j].avg;
				imax = j;
			}
		temp = user[i];
		user[i] = user[imax];
		user[imax] = temp;
	}
}
void decrease_age(student* user, int size) {
	int max_age, imax;
	student temp;
	for (int i = 0; i < size - 1; i++) {
		max_age = user[i].age;
		imax = i;
		for (int j = i; j < size; j++)
			if (user[j].age > max_age) {
				max_age = user[j].age;
				imax = j;
			}
		temp = user[i];
		user[i] = user[imax];
		user[imax] = temp;
	}
}
void max_len_surname(student* user, int size) {
	student maxlen = user[0];
	for (int i = 0; i < size; i++) {
		if (strlen(user[i].surname) > strlen(maxlen.surname)) {
			maxlen = user[i];
		}
	}
	cout << "Студент с самой длинной фамилией:" << endl;
	output_studenta(&maxlen, 1);
}
void swap_max_min(student* user, int size) {
	student maxage = user[0];
	student minage = user[0];
	int ma = 0, mi = 0;
	for (int i = 0; i < size; i++) {
		if (user[i].age > maxage.age) {
			maxage = user[i];
			ma = i;
		}
		if (user[i].age < minage.age) {
			minage = user[i];
			mi = i;
		}
	}
	user[ma] = minage;
	user[mi] = maxage;
}