#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    long double x, y;
    cin >> x >> y;
    cout << (3 * x + 2 >= y && y >= pow(x, 2) ? "Yes" : "No") << endl;
    return 0;
}
