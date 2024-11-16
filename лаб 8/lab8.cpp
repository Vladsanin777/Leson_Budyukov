#include <iostream>

using namespace std;

int main() {
	double EPS = 10e-4, a = 1.0/3.0, result = 0;
	int n = 1;
	while (a>EPS) {
		result += a *= 1.0/((2*n-1)*(2*n+1));
		n++;
	}
	cout<<result<<endl;
}
