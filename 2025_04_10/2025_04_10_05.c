#include <stdio.h>

//while 반복문 개념 정리하기
//20보다 작은 홀수 (자연수) 차례대로 출력하기

int main()
{
    int i = 1;

    while (i < 20)
    {
        printf("%d\n", i);
        i = i + 2;
    }
    
    return 0;
}