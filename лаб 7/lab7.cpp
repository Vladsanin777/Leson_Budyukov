#include <iostream>
#include <cmath>

using namespace std;

class Calculate{
protected:
	double result = 1;
	int k;
public:
	Calculate(int k) : k(k) {}
	void first(){
		this->result *= log10(this->k+1);
		this->k++;
	}
	void second(){
		this->result *= pow(sin(sqrt(20.3*this->k)), 2);
		this->k++;
	}
	double getResult(){
		return this->result;
	}
};

int main() {
	int k = 1, n;
	Calculate * calc = new Calculate(k);
	cin>>n;
	for (k; k <= n; k++) {
		k>0.5 ? calc->first() : calc->second();
	}
	cout<<calc->getResult()<<endl;
	delete calc;
}
