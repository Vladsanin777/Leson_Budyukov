#include <stdio.h>
const unsigned short N;
int main() {
	scanf("%hu", &N);
	short doubleArray[N][N];
	generateDoubleArray(doubleArray);
	printDoubleArray(doubleArray);
	short minElementRows[N], minElementColumns[N];
	findMinElement(
		doubleArray, minElementRows, minElementColumns
	);
	removeMinRowsAndColumns(
		doubleArray, minElementRows, minElementColumns
	);
	printDoubleArray(doubleArray);
	return 0;
}
