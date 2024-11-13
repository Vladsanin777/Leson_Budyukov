#include <iostream>

using namespace std;

class Calculate {
public:
	long double a11, a12, a21, a22;
	Calculate(long double a11, long double a12, long double a21, long double a22) : a11(a11), a12(a12), a21(a21), a22(a22) {}
	long double main() {
		return this->a11 * this->a22 - this->a12 * this->a21;
	}
};

int main() {
	long double a11 = -12, a12 = 19, a21 = 23, a22 = -18;
	cin >> a11 >> a12 >> a21 >> a22;
	cout << Calculate(a11, a12, a21, a22).main() << endl;
	return 0;
}
