//while 과 for 반복문
//1~10 까지 출력 하기
//0을 입력 할시 종료
#include <stdio.h>

int main()
{
    int a = 0;
    int dan = 2;
    /* 
    while (a < 10+1)
    {
        printf("%d\n", a);
        a++;
    }
    */
   if (a < 10)
    {
        for (int i = 1; i < 9; i++)
        {
            for (int i = 1; i < 9+1; i++)
            {
                printf("%d 단 입니다 %d x %d = %d \n",dan, dan, i, dan*i);
            }
            dan++;
            printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
        }
    }

    else
    {
        printf("오류\n");
    }
    return 0;
}