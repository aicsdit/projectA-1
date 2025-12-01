#include <stdio.h>

#define UP 0      // 정렬 오름차순
#define DOWN 1    // 정렬 내림차순

// 배열에서 가장 작은 값을 리턴
int findMin(int a[], int size) {
    int minValue = a[0];
    for(int i = 1; i < size; i++) 
    {
        if(a[i] < minValue) 
        {
            minValue = a[i];
        }
    }
    return minValue;
}

// 배열에서 가장 작은 값의 인덱스를 리턴
int findMin_index(int a[], int size)
{
    int minIndex = 0;
    
    for(int i = 1; i < size; i++) 
    {
        if(a[i] < a[minIndex]) 
        {
            minIndex = i;
        }
    }
    return minIndex;
}

// from 위치부터 가장 작은 값의 인덱스를 리턴
int findMin_index_From(int a[], int size, int from) 
{
    int minIndex = from;

    for(int i = from + 1; i < size; i++) 
    {
        if(a[i] < a[minIndex]) 
        {
            minIndex = i;
        }
    }
    return minIndex;
}

// 배열의 두 값을 교환
void swapValue(int a[], int first, int second) 
{
    int temp = a[first];

    a[first] = a[second];

    a[second] = temp;
}

// 배열 출력
void printArray(int a[], int size) 
{
    printf("[");
    for (int i = 0; i < size; i++) 
    {
        printf("%d", a[i]);
        
        if (i < size - 1) printf(",");
    }
    printf("]\n");
}

// 배열을 뒤집기
void reverse(int a[], int size) 
{
    for(int i = 0; i < size/2; i++) 
    {
        swapValue(a, i, size-1-i);
    }
}

// 정렬 함수
void sort(int a[], int size, int order) 
{
    int minIndex;

    for(int i = 0; i < size; i++) 
    {
        minIndex = findMin_index_From(a, size, i);
        swapValue(a, i, minIndex);
    }

    if(order == DOWN) 
    {
        reverse(a, size);
    }
}

