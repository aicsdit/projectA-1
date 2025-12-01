#include <stdio.h>

int main()
{
    int a, b;

    //scanf 사용, 응용

    printf("두 정수 입력:");

    scanf("%d %d", &a, &b);

    if(a == b)
    {
        printf("두 정수의 값은 같습니다.\n");
    }

    else if(a > b)
    {
        printf("더 큰 수는 %d 입니다.\n", a);
    }

    else
    {
        printf("더 큰 수는 %d 입니다.\n", b);
    }

    return 0;
}