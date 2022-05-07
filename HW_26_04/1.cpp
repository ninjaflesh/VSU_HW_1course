#include <iostream>
#include <ctime>

using namespace std;

struct tochka {
	double X;
	double Y;
};

void vvod_tochka(tochka* a, int n);
void vivod_tochka(tochka* a, int n);
double length(tochka* A, tochka* B);
void max_length(tochka* a, int n);
void min_length(tochka* a, int n);
void min_length1(tochka* a, int n);
void line(tochka* a, int n);

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	const int n = 20;
	tochka* a = new tochka[n];

	vvod_tochka(a, n);
	cout << "Вывод:" << endl;
	vivod_tochka(a, n);

	line(a, n);

	delete a;

	system("pause");
	return 0;
}

void max_length(tochka* a, int n) {
	double max = length(&a[0], &a[1]);
	tochka maxA = a[0], maxB = a[1];
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (length(&a[i], &a[j]) > max)
			{
				max = length(&a[i], &a[j]);
				maxA = a[i]; maxB = a[j];
			}
	cout << "Max Length=" << max << endl;
	cout << "A(" << maxA.X << ";" << maxA.Y << ")  ";
	cout << "A(" << maxB.X << ";" << maxB.Y << ")  " << endl;
}
double length(tochka* A, tochka* B)
{
	return sqrt((A->X - B->X) * (A->X - B->X) + (A->Y - B->Y) * (A->Y - B->Y));
}
void vvod_tochka(tochka* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i].X = rand() % 20 - 10;
		a[i].Y = rand() % 20 - 10;
	}
}
void vivod_tochka(tochka* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << "A" << i << "(" << a[i].X << ";" << a[i].Y << ")  ";
	cout << endl;
}
void min_length(tochka* a, int n) {
	double min = length(&a[0], &a[1]);
	tochka minA = a[0], minB = a[1];
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (length(&a[i], &a[j]) < min) {
				min = length(&a[i], &a[j]);
				minA = a[i]; minB = a[j];
			}
	cout << "Min length=" << min << endl;
	cout << "A(" << minA.X << ";" << minA.Y << ")  ";
	cout << "A(" << minB.X << ";" << minB.Y << ")  " << endl;
}
void min_length1(tochka* a, int n) {
	int s = 0;
	tochka* temp = new tochka[s];
	for (int i = 0; i < n; i++) {
		if ((a[i].X < 0) && (a[i].Y < 0)) {
			s++;
			temp[s] = a[i];
		}
	}
	min_length(temp, s);

	cout << endl;
}
void line(tochka* a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				if ((a[k].X - a[i].X) * (a[j].Y - a[i].Y) == (a[j].X - a[i].X) * (a[k].Y - a[i].Y)) {
					cout << "Точик на одной прямой" << endl;
					cout << "A" << i << "(" << a[i].X << ";" << a[i].Y << ") ";
					cout << "A" << i + 1 << "(" << a[j].X << ";" << a[j].Y << ") ";
					cout << "A" << i + 2 << "(" << a[k].X << ";" << a[k].Y << ")" << endl;
				}
			}
		}
	}
}