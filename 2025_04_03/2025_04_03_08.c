#include <stdio.h>

int main()

//while 반복문
{
    int a,b,c;
    char op;

    printf("계산을 하시겠습니까?\n예) 1\n아니요) 2\n");

    scanf("%d", &c);

    if(c == 2)
    {
        printf("종료\n");
    }

    while (c == 1)
    {
        printf("정수 연산자 정수 순서로 입력해 주새요\n");

        scanf("%d %c %d",&a ,&op ,&b);

        switch (op)
        {
         case '+' : printf("%d %c %d = %d\n",a,op,b,a+b);
            break;
        
        case '-' : printf("%d %c %d = %d\n",a,op,b,a-b);
            break;
        
        case '%' : printf("%d %c %d = %d\n",a,op,b,a%b);
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
    return 0;
}