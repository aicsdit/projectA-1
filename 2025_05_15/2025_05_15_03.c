#include <stdio.h>

//배열을 함수의 매개변수로 넘겨서 처리하기

void printfArray(int a[], int size)
{
    printf("[");

    for (int i = 0; i < size; i++)
    {
        printf("[");

        for (int i = 0; i < size; i++)
        {
            printf("%d", a[i]);

            if (i < size - 1) //끝자리 -1 해서 쉼표가 마지막에 안찍히게 함
                printf(",");
        }

        printf("]");
    }
}

int findMax(int a[], int size)
{
    int maxValue = a[0];// 첫 원소가 제일 큰 값 이라고 설정함

    for(int i = 1; i < size; i++)
    {
        if(a[i] > maxValue)
        {
            maxValue = a[i];
        }
    }
    
    return maxValue;
}

int main()
{
    int a[5] = {100, 4, 20, 200, 90};
    
    int MAX;

    MAX = findMax(a,5);

    //printfArray(a, 5); // [10, 20, 30, 40, 50]

    printf("%d",MAX);
}
