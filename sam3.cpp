#include <cstdio>
typedef unsigned char byte;
int main() {
	const char number[11];
	scanf("%s", number);
	byte len = strlen(number);
	short sum = 0;
	for (const char * i = number + len - (byte)1; i-- > number;)
		sum += *i;
	float result = (float)sum / len + *number - '0';
	printf("%f\n", result);
	return 0;
}

