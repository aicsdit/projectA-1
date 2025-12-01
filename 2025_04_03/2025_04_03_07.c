#include <stdio.h>

int main()
{
    int a,b;
    char op;

    //1. 수식을 입력받아 a,b,op에 값 저장하기
    //2. 입력된 연산자 (op)에 맞는 연산을 처리하고 결과 출력하기
    //3. case 문 사용

    printf("정수 연산자 정수 순서로 입력해 주새요\n");

    scanf("%d %c %d",&a ,&op ,&b);

    switch (op)
    {
        case '+' : printf("%d %c %d = %d\n",a,op,b,a+b);
        break;
        
        case '-' : printf("%d %c %d = %d\n",a,op,b,a-b);
        break;
        
        case '%' : printf("%d %c %d = %d\n",a,op,a/b);
        break;
        
        case '/' : printf("%d %c %d = %f\n",a,op,b,(float)a/b);
        break;
        
        case 'x' :
        case 'X' :
        case '*' : printf("%d %c %d = %d\n",a,op,b,a*b);
        break;
        
        default: printf("오류");
        break;
    }
}