#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int student;
    int i, input;
    int *score;
    int sum = 0;

    //학생 수 입력받기
    printf("학생 수는? : ");
    scanf("%d", &student);

    //학생수만큼의 배열 생성하기
    score = (int *)malloc(student * sizeof(int));

    for (i = 0; i < student; i++) {
        printf("학생 %d 의 점수 : ", i);
        scanf("%d", &input);

        score[i] = input;
        sum += score[i];
    }
    printf("전체 학생의 평균 점수 : %d \n", sum / student);
    free(score);
    return 0;
}