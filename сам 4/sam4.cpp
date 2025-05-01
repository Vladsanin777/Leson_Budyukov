#include <ctime>
#include <cstdlib>
#include <cstdio>

typedef unsigned char byte;

const byte N = 4;

byte arr[N][N];

int main() {
    srand(time(0L));

    byte (*end)[N] = arr + N;
    for (byte (*i)[N] = arr; i < end; i++) {
        byte *endTemp = *i + N;
        for (byte *j = *i; j < endTemp; j++) {
            *j = rand() % 6;
            printf("%hhu ", *j);
        }
		putchar('\n');
    }

    byte count = 0;

    for (byte (*i)[N] = arr; i < end; i++) {
        byte *endTemp = *i + N;
        for (byte *j = *i; j < endTemp; j++)
            if (*j == 0) {
                count++;
                break;
            }
    }
    printf("%hhu\n", count);

    byte queue = 1, indexColumn = 0, sizeQueue, temp;
    for (byte i = 0; i < N; i++) {
        temp = arr[0][i];
        sizeQueue = 1;
        for (byte j = 1; j < N; j++) {
            if (arr[j][i] == temp)
                sizeQueue++;
            else {
                if (queue < sizeQueue) {
                    queue = sizeQueue;
                    indexColumn = i;
                }
                sizeQueue = 1;
                temp = arr[j][i];
            }
        }
        if (queue < sizeQueue) {
            queue = sizeQueue;
            indexColumn = i;
        }
    }
    printf("%hhu\n", indexColumn);
    return 0;
}
