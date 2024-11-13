#include <iostream>

using namespace std;

int main() {
	double EPS = 10e-4, i, result = 0;
	int n = 1;
	do {
		result += i = 1.0/((2*n-1)*(2*n+1));
		n++;
	} while (i>EPS);
	cout<<result<<endl;
}
