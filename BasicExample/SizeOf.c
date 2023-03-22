#include <stdio.h>

int main(void)
{
    printf("char형의 크기 : %lu\n", sizeof(char));
    printf("int형의 크기 : %lu\n", sizeof(int));
    printf("short형의 크기 : %lu\n", sizeof(short));
    printf("long형의 크기 : %lu\n", sizeof(long));
    printf("float형의 크기 : %lu\n", sizeof(float));
    printf("double형의 크기 : %lu\n", sizeof(double));
    printf("long double형의 크기 : %lu\n", sizeof(long double));
}