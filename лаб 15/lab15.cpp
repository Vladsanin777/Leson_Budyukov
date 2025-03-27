#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const unsigned char N = 3, M = 4;
void printArray(char *arr) {
	unsigned char index = 0;
	for (unsigned char i = 0; i < N; i++) {
		putchar('\t');
		for (unsigned char j = 0; j < M; j++)
			printf("%hhu ", arr[index++]);
		putchar('\n');
	}
	putchar('\n');
}
void generateArray(char *arr, const unsigned char length) {
	for (unsigned char i = 0; i < length; i++)
		arr[i] = rand() % 256 - 128;
}
void sumArray(char *arr1, char *arr2, char *arrSum, \
	const unsigned char length) {
	for (unsigned char i = 0; i < length; i++)
		arrSum[i] = arr1[i] + arr2[i];
}
int main() {
	const unsigned char length = N * M;
	char arr1[length], arr2[length], arrSum[length];
	srand(time(NULL));
	generateArray(arr1, length);
	generateArray(arr2, length);
	printArray(arr1);
	printArray(arr2);
	sumArray(arr1, arr2, arrSum, length);
	printArray(arrSum);
}