#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

double f_integral(double x) {
	return pow(1 - x, 2) / pow(x, 2);
}

void integral(function<double(double)> f, double a, double b, double EPS) {
	double h, integral_old, integral_new = 0;
	int n = 1;
	do {
		n *= 2, h = (b - a) / n, integral_old = integral_new, integral_new = 0;
		for (int i = 0; i < n; i++) integral_new += f(a + (i + 0.5) * h) * h;
	} while (abs(integral_new - integral_old) < EPS);
	cout << integral_new << endl;
	return;
}
void lenght_line(double a, double b, double EPS) {
	int n = 2;
	double L = 0, L1 = 0, h;
	while (abs(L - L1) < EPS) {
		L1 = L, L = 0, h = (b - a) / n;
		for (int i = 1; i <= n; i++) {
			L += sqrt(pow(a + h * (i - 1) - (a + i * n), 2) + pow(f_integral(a + h * (i - 1)) - f_integral(a + h * (i - 1)) - f_integral(a + i * h), 2));
		}
		n = pow(n, 2);
	}
	cout << L;
}
int main() {
	double b, a, EPS;
	cin >> a >> b >> EPS;
	integral(f_integral, a, b, EPS);
	lenght_line(a, b, EPS);
	return 0;
}
