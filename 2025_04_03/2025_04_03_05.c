
#include <stdio.h>

int main()
{
    int age, height;
    
    //조건 10살 키 150 이상
    //나이 or 키 둘중 하나라도 조건에 맞지 않으면 다음 코드 실행 x

    printf("당신이 나이는?\n");

    scanf("%d", &age);

    if(age <= 10 - 1)
    {
        printf("탑승 불가\n");
    }

    else
    {
        printf("당신의 키는?\n");

        scanf("%d", &height);

        if(height <= 150-1)
        {
            printf("탑승 불가\n");
        }

        else
        {
            printf("탑승 가능\n");
        }
    }
    return 0;
}