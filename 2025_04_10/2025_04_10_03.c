#include <stdio.h>

int main()
{
    int a, b;

    printf("정수 2개 입력:");

    scanf("%d %d",&a, &b);

    (a > b)? printf("%d\n", a) : printf("%d\n", b);
    
    return 0;
}