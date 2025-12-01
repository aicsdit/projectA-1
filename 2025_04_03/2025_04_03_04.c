#include <stdio.h>

int main()
{
    int age, height;

    //조건 10살 키 150 이상
    //나이 10살 키 150 미만 일시 탑승 불가

    printf("당신이 나이는?\n");

    scanf("%d", &age);

    if(age <= 10 - 1)
    {
        printf("탑승 불가\n");

        return 0;
    }

    printf("당신의 키는?\n");

    scanf("%d", &height);

    if(height <= 150 - 1)
    {
        printf("탑승 불가\n");
        
        return 0;
    }

    else
    {
        printf("탑승 가능\n");
    }
}