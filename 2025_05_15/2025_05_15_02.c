#include <stdio.h>

//다차원 배열 연습
//2차원 행열을 선언하고 화면에 출력하기
int main()
{
    int a[2][3] = 
    {{12,34,56}
    ,{78,4,63}};

    for(int row=0; row<2; row++)
    {
        for(int col=0; col<3; col++)
        {
            printf("%2d ", a[row][col]);
        }
        printf("\n");
    }

    /*
    for(int col=0; col<3; col++)
    {
        for(int row=0; row<2; row++)
        {
            printf("%2d ", a[row][col]);
        }
        printf("\n");
    }
    */
}