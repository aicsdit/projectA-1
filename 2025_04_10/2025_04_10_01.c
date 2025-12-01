#include <stdio.h>

int main()
{
    int a, b, MaxValue;

    printf("정수 2개 입력:");

    scanf("%d %d",&a, &b);

    if (a > b)
    {
        MaxValue = a;
    }
    else
    {
        MaxValue = b;
    } //MaxValue = (a > b)? a : b;

    printf("큰 수는 %d 입니다\n",MaxValue);
    
    return 0;
}