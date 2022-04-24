#include <iostream> 

using namespace std;

struct complex {
	double Re;
	double Im;
};

void input_complex(complex* x);
void output_complex(complex* x);
void plus_complex(complex* x, complex* y, complex* rez);
void minus_complex(complex* x, complex* y, complex* rez);
void proizv_complex(complex* x, complex* y, complex* rez);
void raz_complex(complex* x, complex* y, complex* rez);
double modul_complex(complex* x);
void delenie_complex(complex* x, complex* y, complex* rez);
void obrat_complex(complex* x, complex* rez);
void koef_complex(complex* x, int k, complex* rez);
bool ident_complex(complex* x, complex* y);
bool idz(complex* x, complex* b, complex* c);

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	complex a, b, c;
	input_complex(&a);
	input_complex(&b);
	input_complex(&c);
	cout << idz(&a, &b, &c) << endl;

	system("pause");
	return 0;
}

void input_complex(complex* x) {
	cin >> x->Re >> x->Im;
}
void output_complex(complex* x) {
	if (x->Im >= 0) {
		cout << x->Re << "+" << x->Im << "i" << endl;
	}
	else {
		cout << x->Re << x->Im << "i" << endl;
	}
}
void plus_complex(complex* x, complex* y, complex* rez) {
	rez->Re = x->Re + y->Re;
	rez->Im = x->Im + y->Im;
}
void minus_complex(complex* x, complex* y, complex* rez) {
	rez->Re = x->Re - y->Re;
	rez->Im = x->Im - y->Im;
}
void proizv_complex(complex* x, complex* y, complex* rez) {
	rez->Re = (x->Re * y->Re - x->Im * y->Im);
	rez->Im = (x->Im * y->Re + x->Re * y->Im);
}
void raz_complex(complex* x, complex* y, complex* rez) {
	rez->Re = ((x->Re * y->Re) + (x->Im * y->Im)) / ((pow(y->Re, 2)) + (pow(y->Im, 2)));
	rez->Im = ((x->Im * y->Re) - (x->Re * y->Im)) / ((pow(y->Re, 2)) + (pow(y->Im, 2)));
}
void delenie_complex(complex* x, complex* y, complex* rez) {
	rez->Re = ((x->Re * y->Re) + (x->Im * y->Im)) / ((pow(y->Re, 2) + pow(y->Im, 2)));
	rez->Im = ((x->Im * y->Re) - (x->Re * y->Im)) / ((pow(y->Re, 2) + pow(y->Im, 2)));
}
double modul_complex(complex* x) {
	return sqrt(pow(x->Re, 2) + pow(x->Im, 2));
}
void koef_complex(complex* x, int k, complex* rez) {
	rez->Re = k * x->Re;
	rez->Im = k * x->Im;
}
void obrat_complex(complex* x, complex* rez) {
	rez->Re = (x->Re) / (modul_complex(x) * modul_complex(x));
	rez->Im = (-x->Im) / (modul_complex(x) * modul_complex(x));
}
bool ident_complex(complex* x, complex* y) {
	if ((x->Re != y->Re) || (x->Im != y->Im)) {
		return false;
	}
	return true;
}
bool idz(complex* a, complex* b, complex* c) {
	complex k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k20;
	koef_complex(a, 4, &k1);
	koef_complex(b, 3, &k2);
	koef_complex(c, -7, &k3);
	plus_complex(&k1, &k2, &k4);
	plus_complex(&k4, &k3, &k5);
	proizv_complex(&k5, &k5, &k6); // левая часть 

	proizv_complex(&k1, &k1, &k7);
	proizv_complex(&k2, &k2, &k8);
	proizv_complex(&k3, &k3, &k9);
	proizv_complex(&k1, &k3, &k10);
	proizv_complex(&k2, &k3, &k11);
	proizv_complex(&k1, &k2, &k12);
	koef_complex(&k10, 2, &k13);
	koef_complex(&k11, 2, &k14);
	koef_complex(&k12, 2, &k15);
	plus_complex(&k7, &k8, &k16);
	plus_complex(&k16, &k9, &k17);
	plus_complex(&k17, &k13, &k18);
	plus_complex(&k18, &k14, &k19);
	plus_complex(&k19, &k15, &k20); // правая часть 

	return ident_complex(&k6, &k20);
}