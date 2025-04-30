#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

void printSystem(float** A, float* b, const unsigned char& n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " * x" << j + 1;
            if (j < n - 1) cout << " + ";
        }
        cout << " = " << b[i] << endl;
    }
    cout << endl;
}

void gauss(float** A, float* b, const unsigned char& n) {

    // Прямой ход метода Гаусса
    for (int col = 0; col < n; col++) {
        // Поиск строки с максимальным элементом в текущем столбце
        int max_row = col;
        for (int row = col + 1; row < n; row++) {
            if (abs(A[row][col]) > abs(A[max_row][col])) {
                max_row = row;
            }
        }

        // Перестановка строк
        swap(A[col], A[max_row]);
        swap(b[col], b[max_row]);

        // Нормализация текущей строки
        float div = A[col][col];
        if (abs(div) < EPS) {
            throw runtime_error("Система вырождена или не имеет единственного решения");
        }

        for (int j = col; j < n; j++) {
            A[col][j] /= div;
        }
        b[col] /= div;

        // Исключение переменной из других строк
        for (int row = 0; row < n; row++) {
            if (row != col && abs(A[row][col]) > EPS) {
                double factor = A[row][col];
                for (int j = col; j < n; j++) {
                    A[row][j] -= A[col][j] * factor;
                }
                b[row] -= b[col] * factor;
            }
        }
    }
}


int main() {
    setlocale(LC_ALL, "ru");
    const unsigned char n = 4;
    // Исходная система уравнений
    float** A{ new float* [n] {
        new float[n] {6.4, 7.2, -8.3, 42.0},
        new float[n] {5.8, -8.3, 14.3, -6.2},
        new float[n] {8.6, 7.7, -18.3, 8.8},
        new float[n] {13.2, -5.2, -6.5, 12.2}
    } };

    float* b{ new float[n] {2.23, 17.1, -5.4, 6.5} };

    cout << "Исходная система уравнений:" << endl;
    printSystem(A, b, n);

    try {
        gauss(A, b, n);
        printSystem(A, b, n);
        float* bEnd{ b + n };
        cout << "Решение системы:" << endl;
        for (float* bCurrent{ b }; bCurrent < bEnd; bCurrent++)
            cout << *bCurrent << endl;
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    delete[]b;
    delete[] * A;
    delete[]A[1];
    delete[]A[2];
    delete[]A[3];
    delete[]A;
    return 0;
}