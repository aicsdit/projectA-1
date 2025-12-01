#include <stdio.h>

int main()
{
    char name[256];

    printf("당신의 이름은 무엇 입니까? \n");

    scanf("%s",name);

    printf("%s님 반갑습니다.",name);

    return 0;
}