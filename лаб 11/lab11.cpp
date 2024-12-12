#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> a;
	
	for (int i = 1; i != 0;) {
		cin >> i;
		a.push_back(i);
	}
	reverse(a.begin(), a.end());
	for (vector<int>::iterator i = a.begin(); i - a.begin() != a.size(); i++) {
		cout << *i << endl;
	}
	return 0;
}