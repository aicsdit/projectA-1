#include <stdio.h>

//While 반복문 개념 정리 하기

int main()
{
    int i = 1; // 반복 제어를 위한 변수의 초기화

    while (i < 110+1)
    {
        printf("%d\n", i);
        i = i+1;
    }

    return 0;
}