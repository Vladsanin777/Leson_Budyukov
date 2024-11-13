#include <iostream>
#include <cmath>

using namespace std;
#define EPSILON 10e-5
 
// An example function whose solution is determined using
double func(double x) { return sin(2*x)/cos(x-1);}
 
// Prints root of func(x) with error of EPSILON
int main()
{
    // Initial values assumed
    double a = 1.0, b = 2.2, c = a, fc;
    while ((b-a) >= EPSILON && (fc = func(c = (a+b)/2)) != 0.0)
		fc*func(a) < 0 ? b = c : a = c;
    cout << c << endl;
    return 0;
}

