#include <iostream>
#include <cmath>

using namespace std;

class Calc {
public:
	long double x;
	long double result;
	Calc(long double x) : x(x) {}
	void first() {
		this->result = 0.91 * log10(this->x) + sqrt(this->x);
		return;
	}
	void second() {
		this->result = 1.8*cos(this->x)+3*pow(this->x, 2);
		return;
	}
};

int main() {
	long double x = 0.8, end = 2.0, delta = 0.1;
	x -= delta;
	Calc* calc;
menay_zastavili:
	x += delta;
	calc = new Calc(x);
	if (x > 1) calc->first();
	else calc->second();
	cout <<"x = " << x << "\t" << "y = " << calc->result << endl;
	delete calc;
	if (x<=end) goto menay_zastavili;
	
}