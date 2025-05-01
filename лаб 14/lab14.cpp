#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const size_t N = 10, M = 12;

void printArray(short array[N][M], unsigned short rows, unsigned short cols) {
    for (unsigned short i = 0; i < rows; i++) {
        putchar('\t');
        for (unsigned short j = 0; j < cols; j++)
            printf("%4hd ", array[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

void generateArray(short array[N][M]) {
    for (unsigned short i = 0; i < N; i++)
        for (unsigned short j = 0; j < M; j++)
            array[i][j] = rand() % 1000 - 500;
}

void findMin(short array[N][M], short* min) {
    *min = array[0][0];
    for (unsigned short i = 0; i < N; i++)
        for (unsigned short j = 0; j < M; j++)
            if (array[i][j] < *min) *min = array[i][j];
}

void sortDescending(unsigned short* arr, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] < arr[j]) {
                unsigned short temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

void deleteRow(short array[N][M], unsigned short rowIndex) {
    for (unsigned short i = rowIndex; i < N - 1; i++)
        for (unsigned short j = 0; j < M; j++)
            array[i][j] = array[i + 1][j];
}

void deleteColumn(short array[N][M], unsigned short colIndex) {
    for (unsigned short i = 0; i < N; i++)
        for (unsigned short j = colIndex; j < M - 1; j++)
            array[i][j] = array[i][j + 1];
}

int main() {
    srand(time(NULL));
    short array[N][M];
    generateArray(array);
    printf("Original array:\n");
    printArray(array, N, M);

    short min;
    findMin(array, &min);

    // Сбор всех строк и столбцов с минимальным элементом
    unsigned short rows[N * M], cols[N * M];
    int count = 0;
    for (unsigned short i = 0; i < N; i++)
        for (unsigned short j = 0; j < M; j++)
            if (array[i][j] == min) {
                rows[count] = i;
                cols[count] = j;
                count++;
            }

    // Уникальные строки
    unsigned short uniqueRows[N];
    int uniqueRowCount = 0;
    for (int i = 0; i < count; i++) {
        int exists = 0;
        for (int j = 0; j < uniqueRowCount; j++)
            if (uniqueRows[j] == rows[i]) { exists = 1; break; }
        if (!exists) uniqueRows[uniqueRowCount++] = rows[i];
    }

    // Уникальные столбцы
    unsigned short uniqueCols[M];
    int uniqueColCount = 0;
    for (int i = 0; i < count; i++) {
        int exists = 0;
        for (int j = 0; j < uniqueColCount; j++)
            if (uniqueCols[j] == cols[i]) { exists = 1; break; }
        if (!exists) uniqueCols[uniqueColCount++] = cols[i];
    }

    // Сортировка индексов
    sortDescending(uniqueRows, uniqueRowCount);
    sortDescending(uniqueCols, uniqueColCount);

    // Удаление строк
    for (int i = 0; i < uniqueRowCount; i++)
        deleteRow(array, uniqueRows[i]);

    // Удаление столбцов
    for (int i = 0; i < uniqueColCount; i++)
        deleteColumn(array, uniqueCols[i]);

    // Вывод результата
    printf("After deletion:\n");
    printArray(array, N - uniqueRowCount, M - uniqueColCount);
    printf("Min element: %hd\nDeleted rows: %d\nDeleted columns: %d\n",
        min, uniqueRowCount, uniqueColCount);

    return 0;
}