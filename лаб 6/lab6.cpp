#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int k = 1, n;
	double result = 0;
	cin>>n;
	for (k; k <= n; k++) {
		result += 1/pow(2*k+1, 2);
	}
	cout<<result<<endl;
}
