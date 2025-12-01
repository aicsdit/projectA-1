#include <stdio.h>

#define UP 0      //정렬 오름차순
#define DOWN 1    //정렬 내림차순

// 배열에서 가장 작은 값을 찾음 -> 가장 작은 값을 0번 그 다음 값을 1번 으로 바꿈
// 배열의 값 에서 작은 순서대로 정리

int findMin(int a[], int size) // 배열에서 가장 작은 숫자를 리턴
{
    int minValue = a[0];

    for(int i = 0; i < size; i++)
    {
        if(a[i] < minValue)
        {
            minValue = a[i];
        }
    }
    return minValue;
}

int findMin_index(int a[], int size) // 배열의 가장 작은 숫자를 리턴
{
    int minIndex = 0;

    for(int i = 1; i <size; i++)
    {
        if(a[i] < a[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

int findMin_index_From(int a[], int size, int from) // 배열의 가장 작은 숫자의 인덱스 값을 출력
{
    int minIndex = from;

    for(int i = from; i <size; i++)
    {
        if(a[i] < a[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

void swapValue(int a[], int first, int second) // 배열의 값을 서로 바꿈
{
    int temp = a[first];

    a[first] = a[second];
    a[second] = temp;
}

void printArray(int a[], int size) // 배열값을 출력
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
        if (i < size - 1) printf(",");
    }
    printf("]\n");
}

void reverse(int a[], int size) // 배열 값을 큰 숫자 순서로 정렬
{
    for(int i = 0; i < (size/2); i++)
    {
        swapValue(a,i,size-1);
    }
}

void sort(int a[], int size, int order) // define을 이용해서 오름차순 내림차순으로 정렬
{
    int minIndex;

    for(int i = 0; i < 5; i++)
    {
        minIndex = findMin_index_From(a,5,i);
        swapValue(a,i,minIndex);
    }
    if(order == DOWN)
    {
        reverse(a,5);
    }
}

int main()
{
    int a[] = {100, 4, 20, 200, 90};

    int min;
    int minIndex;

    min = findMin(a,5);
    minIndex = findMin_index(a,5);


    printf("정렬 전\n");
    printArray(a,5);

    sort(a,5,DOWN);

    printf("정렬 후\n");
    printArray(a,5);

    sort(a,5,UP);
}