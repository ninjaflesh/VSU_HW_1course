#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

struct pupils {
	int id;
	char firstname[20];
	char lastname[20];
	int age;
	float avg;
	char email[60];
};

void load_db(pupils* mass, int n);
void output_pupils(pupils* mass, int n);
void min_id(pupils* mass, int n);
void max_id(pupils* mass, int n);
void min_age(pupils* mass, int n);
void max_age(pupils* mass, int n);
void min_avg(pupils* mass, int n);
void max_avg(pupils* mass, int n);
void descending_firstname(pupils* mass, int n);
void ascending_firstname(pupils* mass, int n);
void descending_lastname(pupils* mass, int n);
void ascending_lastname(pupils* mass, int n);
void descending_email(pupils* mass, int n);
void ascending_email(pupils* mass, int n);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 1000;
	pupils* db = new pupils[n];
	load_db(db, n);

	int mode;
	do {
		cout << "Выберите: \n0-EXIT" << endl;
		cout << "1-Вывод, 21-Мин. id, 22-Макс. id" << endl;
		cout << "31-Мин. возраст, 32-Макс. возраст, 41-Мин. avg" << endl;
		cout << "42-Макс. avg, 51-Убы. имя ,52-Возр. имя " << endl;
		cout << "61-Убы. фамилия, 62-Возр. фамилия, 71-Убы. почта" << endl;
		cout << "72-Возр. почта" << endl;
		cin >> mode;
		switch (mode) {
		case 1:output_pupils(db, n); break;
		case 21:min_id(db, n); break;
		case 22:max_id(db, n); break;
		case 31:min_age(db, n); break;
		case 32:max_age(db, n); break;
		case 41:min_avg(db, n); break;
		case 42:max_avg(db, n); break;
		case 51:descending_firstname(db, n); break;
		case 52:ascending_firstname(db, n); break;
		case 61:descending_lastname(db, n); break;
		case 62:ascending_lastname(db, n); break;
		case 71:descending_email(db, n); break;
		case 72:ascending_email(db, n); break;
		}
	} while (mode);

	system("pause");
	return 0;
}

void load_db(pupils* mass, int n) {
	ifstream source_s;
	source_s.open("d:\\cpp\\source.txt");

	int s = 0;
	while (source_s.peek() != EOF) {
		source_s >> mass[s].id;
		source_s >> mass[s].firstname;
		source_s >> mass[s].lastname;
		source_s >> mass[s].age;
		source_s >> mass[s].avg;
		source_s >> mass[s].email;
		s++;
	}
	source_s.close();
}
void output_pupils(pupils* mass, int n) {
	for (int i = 0; i < n; i++) {
		cout << mass[i].id << " ";
		cout << mass[i].firstname << " ";
		cout << mass[i].lastname << " ";
		cout << mass[i].age << " ";
		cout << mass[i].avg << " ";
		cout << mass[i].email << " " << endl;
	}
}
void min_id(pupils* mass, int n) {
	ofstream output_s;
	output_s.open("d:\\cpp\\output.txt");
	pupils t;
	int min_id = mass[0].id;
	for (int i = 0; i < n; i++) {
		if (mass[i].id < min_id) {
			min_id = mass[i].id;
			t = mass[i];
		}
	}
	output_s << "Min id: " << min_id << endl;
	output_s << t.id << " " << t.firstname << " " << t.lastname << " " << t.age << " " << t.avg << " " << t.email;
	output_s.close();
}
void max_id(pupils* mass, int n) {
	ofstream output_s;
	output_s.open("d:\\cpp\\output.txt");
	int max_id = mass[0].id;
	pupils t;
	for (int i = 0; i < n; i++) {
		if (mass[i].id > max_id) {
			max_id = mass[i].id;
			t = mass[i];
		}
	}
	output_s << "Max id: " << max_id << endl;
	output_s << t.id << " " << t.firstname << " " << t.lastname << " " << t.age << " " << t.avg << " " << t.email;
	output_s.close();
}
void min_age(pupils* mass, int n) {
	ofstream output_s;
	output_s.open("d:\\cpp\\output.txt");
	int min_age = mass[0].age;
	pupils t;
	for (int i = 0; i < n; i++) {
		if (mass[i].age < min_age) {
			min_age = mass[i].age;
			t = mass[i];
		}
	}
	output_s << "Min age: " << min_age << endl;
	output_s << t.id << " " << t.firstname << " " << t.lastname << " " << t.age << " " << t.avg << " " << t.email;
	output_s.close();
}
void max_age(pupils* mass, int n) {
	ofstream output_s;
	output_s.open("d:\\cpp\\output.txt");
	int max_age = mass[0].age;
	pupils t;
	for (int i = 0; i < n; i++) {
		if (mass[i].age > max_age) {
			max_age = mass[i].age;
			t = mass[i];
		}
	}
	output_s << "Max age: " << max_age << endl;
	output_s << t.id << " " << t.firstname << " " << t.lastname << " " << t.age << " " << t.avg << " " << t.email;
	output_s.close();
}
void min_avg(pupils* mass, int n) {
	ofstream output_s;
	output_s.open("d:\\cpp\\output.txt");
	float min_avg = mass[0].avg;
	pupils t;
	for (int i = 0; i < n; i++) {
		if (mass[i].avg < min_avg) {
			min_avg = mass[i].avg;
			t = mass[i];
		}
	}
	output_s << "Min avg: " << min_avg << endl;
	output_s << t.id << " " << t.firstname << " " << t.lastname << " " << t.age << " " << t.avg << " " << t.email;
	output_s.close();
}
void max_avg(pupils* mass, int n) {
	ofstream output_s;
	output_s.open("d:\\cpp\\output.txt");
	float max_avg = mass[0].avg;
	pupils t;
	for (int i = 0; i < n; i++) {
		if (mass[i].avg > max_avg) {
			max_avg = mass[i].avg;
			t = mass[i];
		}
	}
	output_s << "Max avg: " << max_avg << endl;
	output_s << t.id << " " << t.firstname << " " << t.lastname << " " << t.age << " " << t.avg << " " << t.email;
	output_s.close();
}
void descending_firstname(pupils* mass, int n) {
	ofstream output_s;
	output_s.open("d:\\cpp\\output.txt");
	pupils* temp_m = new pupils[n];
	for (int i = 0; i < n; i++) {
		temp_m[i] = mass[i];
	}
	pupils t;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (strlen(temp_m[j].firstname) < strlen(temp_m[j + 1].firstname)) {
				t = temp_m[j];
				temp_m[j] = temp_m[j + 1];
				temp_m[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		output_s << temp_m[i].id << " ";
		output_s << temp_m[i].firstname << " ";
		output_s << temp_m[i].lastname << " ";
		output_s << temp_m[i].age << " ";
		output_s << temp_m[i].avg << " ";
		output_s << temp_m[i].email << " " << endl;
	}
	output_s.close();
}
void ascending_firstname(pupils* mass, int n) {
	ofstream output_s;
	output_s.open("d:\\cpp\\output.txt");
	pupils* temp_m = new pupils[n];
	for (int i = 0; i < n; i++) {
		temp_m[i] = mass[i];
	}
	pupils t;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (strlen(temp_m[j].firstname) > strlen(temp_m[j + 1].firstname)) {
				t = temp_m[j];
				temp_m[j] = temp_m[j + 1];
				temp_m[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		output_s << temp_m[i].id << " ";
		output_s << temp_m[i].firstname << " ";
		output_s << temp_m[i].lastname << " ";
		output_s << temp_m[i].age << " ";
		output_s << temp_m[i].avg << " ";
		output_s << temp_m[i].email << " " << endl;
	}
	output_s.close();
}
void descending_lastname(pupils* mass, int n) {
	ofstream output_s;
	output_s.open("d:\\cpp\\output.txt");
	pupils* temp_m = new pupils[n];
	for (int i = 0; i < n; i++) {
		temp_m[i] = mass[i];
	}
	pupils t;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (strlen(temp_m[j].lastname) < strlen(temp_m[j + 1].lastname)) {
				t = temp_m[j];
				temp_m[j] = temp_m[j + 1];
				temp_m[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		output_s << temp_m[i].id << " ";
		output_s << temp_m[i].firstname << " ";
		output_s << temp_m[i].lastname << " ";
		output_s << temp_m[i].age << " ";
		output_s << temp_m[i].avg << " ";
		output_s << temp_m[i].email << " " << endl;
	}
	output_s.close();
}
void ascending_lastname(pupils* mass, int n) {
	ofstream output_s;
	output_s.open("d:\\cpp\\output.txt");
	pupils* temp_m = new pupils[n];
	for (int i = 0; i < n; i++) {
		temp_m[i] = mass[i];
	}
	pupils t;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (strlen(temp_m[j].lastname) > strlen(temp_m[j + 1].lastname)) {
				t = temp_m[j];
				temp_m[j] = temp_m[j + 1];
				temp_m[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		output_s << temp_m[i].id << " ";
		output_s << temp_m[i].firstname << " ";
		output_s << temp_m[i].lastname << " ";
		output_s << temp_m[i].age << " ";
		output_s << temp_m[i].avg << " ";
		output_s << temp_m[i].email << " " << endl;
	}
	output_s.close();
}
void descending_email(pupils* mass, int n) {
	ofstream output_s;
	output_s.open("d:\\cpp\\output.txt");
	pupils* temp_m = new pupils[n];
	for (int i = 0; i < n; i++) {
		temp_m[i] = mass[i];
	}
	pupils t;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (strlen(temp_m[j].email) < strlen(temp_m[j + 1].email)) {
				t = temp_m[j];
				temp_m[j] = temp_m[j + 1];
				temp_m[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		output_s << temp_m[i].id << " ";
		output_s << temp_m[i].firstname << " ";
		output_s << temp_m[i].lastname << " ";
		output_s << temp_m[i].age << " ";
		output_s << temp_m[i].avg << " ";
		output_s << temp_m[i].email << " " << endl;
	}
	output_s.close();
}
void ascending_email(pupils* mass, int n) {
	ofstream output_s;
	output_s.open("d:\\cpp\\output.txt");
	pupils* temp_m = new pupils[n];
	for (int i = 0; i < n; i++) {
		temp_m[i] = mass[i];
	}
	pupils t;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (strlen(temp_m[j].email) > strlen(temp_m[j + 1].email)) {
				t = temp_m[j];
				temp_m[j] = temp_m[j + 1];
				temp_m[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		output_s << temp_m[i].id << " ";
		output_s << temp_m[i].firstname << " ";
		output_s << temp_m[i].lastname << " ";
		output_s << temp_m[i].age << " ";
		output_s << temp_m[i].avg << " ";
		output_s << temp_m[i].email << " " << endl;
	}
	output_s.close();
}
