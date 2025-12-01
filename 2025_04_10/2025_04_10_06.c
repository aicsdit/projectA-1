//while 과 for 반복문
//1~10 까지 출력 하기

#include <stdio.h>

void gugudan()
{
    int a = 0;

    printf("입력값 :");

    scanf("%d", &a);

    /* 
    while (a < 10+1)
    {
        printf("%d\n", a);
        a++;
    }
    */
   if (a < 10)
    {
        for (int i = 1; i < 9+1; i++)
        {      
            printf("%d x %d = %d \n", a, i, a*i);
        }
    }
    else
    {
        printf("오류\n");
    }
}

int main()
{
    gugudan;
}