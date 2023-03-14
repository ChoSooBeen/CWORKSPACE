#include <stdio.h>

int main(void){
    int num = 10;
    int *p = &num;

    //직접 참조
    printf("num의 주소 : %u\n", &num);
    printf("직접 참조 값: %d\n", num);

    //간접 참조
    printf("num의 주소 : %u\n", p);
    printf("간접 참조 값: %d\n", *p);

    return 0;
}