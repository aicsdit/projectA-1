#include <stdio.h>

int main()
{
    int a, b;

    //scanf 홀짝 계산
    //숫자 별로 는,은 을 맞게 사용하기
    //0 1 3 6 7 8
    //2 4 5 9

    printf("정수 입력 : ");

    scanf("%d", &a);

    b = a%10;

    if(a==0||a==1||a==3||a==6|a==7||a==8)
    {
        printf("%d은 ", b);

        if(a%2 == 1)
        {
            printf("홀수 입니다.\n");
        }
        else
        {
            printf("홀수 오류");
        }
        return 0;
    }

    else
    {
        printf("%d는 ", b);

           if(a%2 == 0)
          {
            printf("짝수 입니다.\n");
          }
          else
          {
            printf("짝수 오류");
          }
          return 0;
    }

    return 0;
}