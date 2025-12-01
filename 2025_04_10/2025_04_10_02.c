#include <stdio.h>

int main()
{
    int a, b;

    printf("정수 2개 입력:");

    scanf("%d %d",&a, &b);

    printf("큰 수는 %d 입니다\n",(a > b? a : b));
    
    return 0;
}