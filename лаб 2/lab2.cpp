#include <iostream>
#include <cmath>

using namespace std;

class Calculate {
public:
	static long double a(long double *x, long double *y, long double *z) {
		return sqrt(*z * *x * sin(2 * *x) + exp(-*x) * (*x + *y));
	}
	static long double b(long double* x, long double* y, long double* z) {
		return cos(pow(*x, 3)) - (*x / sqrt(pow(*z, 2) + pow(*y, 2)));
	}
};

int main()
{
	long double x, y, z;
	cin >> x >> y >> z;
	cout << "a = " << Calculate::a(&x, &y, &z) << "\tb = " << Calculate::b(&x, &y, &z) << endl;
	return 0;
}