#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Первая функция: f(x) = (2x - 1) / sqrt(x^2 + 1)
double function1(double x) {
    return (2 * x - 1) / sqrt(x * x + 1);
}

// Вторая функция: f(x) = ln(sqrt(9x^2 + 2) + 3x)
double function2(double x) {
    return log(sqrt(9 * x * x + 2) + 3 * x);
}

// Функция для вычисления первой производной численным методом
double firstDerivative(double (*f)(double), double x, double h = 1e-5) {
    int pme = -1, i = 1;
    float a, y1, y2 = f(x + 5);
    do {
        y1 = y2;
        pme = pme * (-1);
        a = x + (float)pme / i;
        y2 = (f(a+h) - f(a)) / h;
        i++;
    } while (fabs(y2 - y1) > h);
    return y2;
}

// Функция для вычисления второй производной численным методом
double secondDerivative(double (*f)(double), double x, double h = 1e-5) {
    int pme = -1, i = 1;
    float a, y1, y2 = f(x + 5);
    do {
        y1 = y2;
        pme = pme * (-1);
        a = x + (float)pme / i;
        y2 = (firstDerivative(f, a + h) - firstDerivative(f, a)) / h;
        i++;
    } while (fabs(y2 - y1) > h);
    return y2;
}

int main() {
    setlocale(LC_ALL, "ru");
    int choice;
    double x;

    cout << "Выберите функцию:\n";
    cout << "1. f(x) = (2x - 1) / sqrt(x^2 + 1)\n";
    cout << "2. f(x) = ln(sqrt(9x^2 + 2) + 3x)\n";
    cout << "Введите номер функции (1 или 2): ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        cout << "Неверный выбор функции!\n";
        return 1;
    }

    cout << "Введите точку x для вычисления производных: ";
    cin >> x;

    double (*selectedFunction)(double) = (choice == 1) ? function1 : function2;

    // Вычисляем производные
    double f1 = firstDerivative(selectedFunction, x);
    double f2 = secondDerivative(selectedFunction, x);

    // Выводим результаты с высокой точностью
    cout << fixed << setprecision(10);
    cout << "\nРезультаты в точке x = " << x << ":\n";
    cout << "Первая производная: " << f1 << "\n";
    cout << "Вторая производная: " << f2 << "\n";

    return 0;
}