#include <iostream>
using namespace std;
int main()
{
    short numbers[10];
    for (unsigned char i = 0; i < 10; i++)
        cin >> numbers[i];
    short indexMin, numberMin = -32768, element;
    bool ifNoElement = true;
    for (unsigned char i = 0; i < 10; i++) {
        element = numbers[i];
        if (ifNoElement && element % 2 == 0)
            ifNoElement = false;
        else if (!(numberMin > element && \
            element % 2 == 1)) continue;
        indexMin = i, numberMin = element;
    }
    if (ifNoElement) cout << "N0 "; else

    cout << indexMin << endl;
    for (unsigned char i = 0; i < 10; i++)
        cout << numbers[i] << ' ';

}
