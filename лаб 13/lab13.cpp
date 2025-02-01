#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const unsigned short N = 1200;
void printArray(short arrayPrint[N][N]){
	for (unsigned short indexVertical = 0; 
		indexVertical < N; indexVertical++
	) {
		putchar('\t');
		for (unsigned short indexHorisontal = 0; 
			indexHorisontal < N; indexHorisontal++
		)
			printf("%hd ", 
				arrayPrint[indexVertical][indexHorisontal]
			);
		putchar('\n');
	}
	putchar('\n');
	return;
}
void generateArray(short arrayGenerate[N][N]) {
	for (unsigned short indexVertical = 0;
		indexVertical < N; indexVertical++
	)
		for (unsigned short indexHorisontal = 0;
			indexHorisontal < N; indexHorisontal++
		)
			arrayGenerate[indexVertical][indexHorisontal] = \
				rand() * 2 % 65535 - 32768;
	return;
}
void getBasicArray(
	short doubleArray[N][N], 
	short basicArray[N]
) {
	for (unsigned short index = 0;
		index < N; index++
	)
		basicArray[index] = doubleArray[index][index];
	return;
}
short minElementBasicArray(
	short *basicArray, unsigned short *columnAndRow \
) {
	short minElement = 32767, intermediate;
	for (unsigned short index = 0;
		index < N; index++
	)
		if ((intermediate = basicArray[index]) < minElement)
			minElement = intermediate, *columnAndRow = index;
	return minElement;
}
int main() {
	srand(time(0));
	short doubleArray[N][N];
	generateArray(doubleArray);
	printArray(doubleArray);
	short basicArray[N];
	unsigned short columnAndRow;
	getBasicArray(doubleArray, basicArray);
	short minElement = minElementBasicArray( 
		basicArray, &columnAndRow
	);
	printf("Min: %hd\nColumn: %hu\nRow: %hu\n", \
		minElement, columnAndRow, columnAndRow);
	return 0;
}
