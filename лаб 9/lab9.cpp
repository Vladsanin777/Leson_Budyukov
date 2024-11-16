#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
	return pow(1-x, 2) / pow(x, 2);
}
double g(double x) {
	return -2 * (1 - x) * x * (x + 1) / pow(x, 3);
}
int main() {
	double b, a;
	cin>>a>>b;
	double h, EPS = 0.01, integral_old, integral_new = 0;
	int n = 1;
	do {
		n *= 2, h = (b-a)/n, integral_old = integral_new, integral_new = 0;
		for (int i = 0; i < n; i++) integral_new += f(a+(i+0.5)*h)*h;
	} while (abs(integral_new - integral_old) < EPS);
	cout << integral_new << endl;
	
	h = (b - a) / (n = 1000);
    double integral = 0.0, x1, x2;

    for (int i = 0; i < n; ++i) {
        x1 = a + i * h, x2 = a + (i + 1) * h, integral += 0.5 * (g(x1) + g(x2)) * h;
    }

    cout << integral << endl;
}

