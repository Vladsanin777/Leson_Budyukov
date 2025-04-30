#define  _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

int main() {
    printf("Sokolovaay\t386\t4\t3\n");
    // d = dicimal o = octal x = sixteen
    long long d, o, x;
    scanf("%lld%llo%llx", &d, &o, &x);
    printf("Integers:\t%lld\t%llo\t%llx\n", d, o, x);
    printf("\t%7.2e%\t%2.8e\t%1.6E\n", (long double )d, (long double)o, (long double)x);
    // d6_8 = %6.8llf d_ = %llf
    long double d6_8, d_;
    scanf("%Lf%Lf", &d6_8, &d_);
    printf("Float:\t%6.8Lf\t%Lf\n", d6_8, d_);
    printf("\t%6.8Le\t%Le", d6_8, d_);

    char s[100];
    scanf("%s", &s);
    printf("String:\t%s\n", s);
}
