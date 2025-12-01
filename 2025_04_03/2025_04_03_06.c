#include <stdio.h>

int main()
{
    int a,b;
    char op; //연산자 문자 +,-,*,%

    //1. 수식을 입력받아 a,b,op에 값 저장하기
    //2, 입력된 연산자 (op)에 맞는 연산을 처리하고 결과 출력하기

    printf("정수 연산자 정수 순서로 입력해 주새요\n");

    scanf("%d %c %d",&a ,&op ,&b);

    printf("입력값 %d %c %d 를 받았습니다.\n", a, op, b);

    if(op == '+')
    {
        printf("%d %c %d = %d\n",a,op,b,a+b);
    }
    else if(op == '-')
    {
        printf("%d %c %d = %d\n",a,op,b,a-b);
    }
    else if(op == '*' || 'x' || 'X')
    {
        printf("%d %c %d = %d\n",a,op,b,a*b);
    }
    else if(op == '/')
    {
        printf("%d %c %d = %f\n",a,op,b,(float)a/b);
    }
    else if (op == '&')
    {
        printf("%d %c %d = %d\n", a, op, b, a%b);
    }
    else
    {
        printf("오류");
    }

    return 0;

}
