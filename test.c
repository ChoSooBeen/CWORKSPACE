#include <stdio.h>
int main(){
    int line;
    int i;
    int star;
    int star2;
    int space;
    printf("몇층의 피라미드를 입력하실 건가요?\n");
    scanf("%d", &line);
    for (i = 0; i < line; i++)
    {
        for (space = i; space < line - 1; space++)
        {
            printf(" ");
        }
        for (star = 0; star <= i; star++)
        {
            printf("*");
        }
        for (star2 = 1; star2 <= i; star2++)
        {
            printf("*");
        }
        printf("\n"); // 여기에 붙어야 하는 이유는 안그러면 * 출력 될때마다 다른 줄로 넘어가니
    }
    return 0;
}