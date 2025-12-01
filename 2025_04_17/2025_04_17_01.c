#include <stdio.h>

int input_dan()
{
    int input;

    printf("출력할 구구단 : (종료:0)\n");
    
    scanf("%d", &input);

    return input;
}

int gugudan()
{
    int dan, i;

    while (1)
    {
        dan = input_dan();

        if(dan == 0)
        {
            return 0;
        }

        for(i = 1; i < 9+1; i++)
        {
            printf("%d x %d = %d\n",dan, i, dan*i);
        }
    }//while
}//메인

int main()
{
    gugudan();

    printf("구구단 종료합니다\n");
    
    return 0;
}