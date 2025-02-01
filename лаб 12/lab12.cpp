#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const unsigned short N = 120;
namespace basic {
    void arrayCopy(short* arrayFirst, short* arraySecond) {
        memcpy(arraySecond, arrayFirst, N * sizeof(short));
    }

    void swap(short* first, short* second) {
        short temp = *first;
        *first = *second;
        *second = temp;
    }
    void printArray(short* arrayPrint) {
        for (unsigned short index = 0; index < N; index++)
            printf("%d ", arrayPrint[index]);
        putchar('\n');
    }
    void generate(short* arrayGenerate) {
        for (unsigned short index = 0; index < N; index++)
            arrayGenerate[index] = rand() * 2 % 65535 - 32768;
    }
}
namespace sort {
    class QuickSort {
    private:
        unsigned short countSwaps = 0, \
            countPlasses = 0, \
            countComparison = 0;
    public:
        explicit QuickSort(
            short* arrayQuick, const unsigned short low, const unsigned short high
        ) {
            quickSort(arrayQuick, low, high);
            printf(
                "Quick sort\nNumber of swaps: %hu\nNumber of comparissons: %hu\nNumber of plasses: %hu\n",
                countSwaps, countComparison, countPlasses
            );
        }
    private:
        void quickSort(
            short* arrayQuick, const unsigned short low, const unsigned short high
        ) {
            if (low < high) {
                short middle = arrayQuick[(low + high) / 2], \
                    i = low, j = high;
                countPlasses++;
                do {
                    while (arrayQuick[i] < middle) i++;
                    while (arrayQuick[j] > middle) j--;
                    if (i <= j) {
                        basic::swap(&arrayQuick[i], &arrayQuick[j]);
                        i++, j--, countSwaps++, countComparison++;
                    }
                } while (i <= j);
                quickSort(arrayQuick, low, j);
                quickSort(arrayQuick, i, high);
            }
        }
    };
    void shellSort(short* arrayShell, const unsigned short count) {
        unsigned short steps[50], counter = 0,
            countSwaps = 0, countComparison = 0, \
            countPlasses = 0;
        for (short i = 0; ; i++) {
            short sedgewick = i % 2 == 0 ? \
                9 * ((1 << i) - (1 << (i / 2))) + 1 : \
                (1 << (i + 2)) - 3 * (1 << ((i + 1) / 2)) + 1;
            if (sedgewick >= count) break;
            steps[counter++] = sedgewick;
        }
        for (short i = counter - 1; i >= 0; i--) {
            short step = steps[i];
            countPlasses++;
            for (short j = step; j < count; j++) {
                short temp = arrayShell[j], g = j;
                while (g >= step && arrayShell[g - step] > temp)
                    arrayShell[g] = arrayShell[g - step], \
                    g -= step, countSwaps++, \
                    countComparison++;
                arrayShell[g] = temp, countSwaps++;
            }
        }
        printf(
            "Shell sort\nNumber of swaps: %hu\nNumber of comparissons: %hu\nNumber of plasses: %hu\n",
            countSwaps, countComparison, countPlasses
        );
    }
}

int main() {
    srand(time(0));
    short arrayQuick[N], arrayShell[N];
    basic::generate(arrayQuick);
    
    basic::printArray(arrayQuick);
    
    basic::arrayCopy(arrayQuick, arrayShell);
    
    sort::QuickSort(arrayQuick, 0, N-1);
    basic::printArray(arrayQuick);
    
    sort::shellSort(arrayShell, N);
    basic::printArray(arrayQuick);
    return 0;
}
