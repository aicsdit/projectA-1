#include <stdio.h>
#include "s.h"

int main()
{
    int a[5];

    char inFileName[100];
    char outFileName[100];
    
    FILE *fp; // 입력용 파일 변수
    FILE *ft; // 출력용 파일 변수

    // 0. 처리할 파일명 입력받기
    printf("입력 파일명 : ");
    scanf("%s", inFileName);
    printf("출력 파일명 : ");
    scanf("%s", outFileName);

    // 1. 파일 열기(읽기 모드로 설정)
    fp = fopen(inFileName, "r");
    if(fp == NULL) 
    {
        printf("입력파일 : [%s] 열기 실패하였습니다. (프로그램 종료)", inFileName);
        return 0;
    }

    printf("입력열기 성공 : [%s]\n", inFileName);

    // 2. 출력 파일 열기(쓰기 모드로 설정)
    ft = fopen(outFileName, "w");
    if(ft == NULL) 
    {
        printf("출력파일 : [%s] 열기 실패하였습니다. (프로그램 종료)", outFileName);

        fclose(fp); // 이미 연 입력 파일은 닫아줍니다.

        return 0;
    }
    
    printf("출력열기 성공 : [%s]\n", outFileName);

    // 3. 오픈한 파일에서 정수 값 5개 읽어 배열 a에 저장
    for(int i = 0; i < 5; i++) 
    {
        if(fscanf(fp, "%d", &a[i]) != 1) 
        {
            printf("정수 %d번째를 읽지 못했습니다. (프로그램 종료)\n", i+1);

            fclose(fp);

            fclose(ft);

            return 0;
        }

        printf("파일에서 정수 %d 개를 읽었습니다\n", i+1);
    }

    // 4. 읽은 정수값을 출력 파일에 저장

    sort(a,5,UP);

    for(int i = 0; i < 5; i++) 
    {
        fprintf(ft, "%d = [%d]\n", i+1, a[i]);
    }

    printf("파일에 자료를 출력하였습니다\n");

    // 5. 파일 닫기
    fclose(fp);
    printf("파일을 닫았습니다 : [%s]\n", inFileName);
    fclose(ft);
    printf("파일을 닫았습니다 : [%s]\n", outFileName);

    return 0;
}
