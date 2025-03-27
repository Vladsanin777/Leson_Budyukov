#include <cstdio>
#include <cstring>
typedef unsigned char byte;
int main() {
	char number[11];
	scanf("%s", number);
	byte len = strlen(number);
	short sum = 0;
	for (const char * i = number + len; i-- > number;)
		sum += *i;
	float result = (float)sum / len + (*number - ('0' << 1));
	printf("%f\n", result);
	return 0;
}

