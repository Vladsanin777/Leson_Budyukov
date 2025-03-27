#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void printBinary(unsigned int number, unsigned char length) {
	for (unsigned char i = length - 1; i != 255; i--)
		printf("%hhu", 0 < (number & (1 << i)));
	putchar('\n');
}
int main() {
	unsigned int number;
	scanf("%u", &number);
	unsigned char length = sizeof number * 8;
	printBinary(number, length);
	for (unsigned char i = 0; i < length; i += 2)
		number &= ~(1 << i);
	printBinary(number, length);

	printf("%u\n", number);
}