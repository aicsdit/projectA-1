#include <stdio.h>
#include "s.h"

// 파일 이름을 입력받는 함수
void file_name(char Input_name[100], char Output_name[100]) 
{
    printf("입력용 파일 이름 : ");
    scanf("%s", Input_name);

    printf("출력용 파일 이름 : ");
    scanf("%s", Output_name);
}
// 파일을 여는 함수
int file_open(const char *input_name, FILE **Ip) 
{
    *Ip = fopen(input_name, "r");
    if (*Ip == NULL) 
    {
        printf("입력 파일 [%s] 열기 실패했습니다.\n", input_name);
        return 0;
    }
    printf("입력 파일 [%s] 열기 성공했습니다.\n", input_name);
    return 1;
}
// 파일에서 정수 5개를 읽어오는 함수
int file_output(FILE *Ip, int a[5]) 
{
    for (int i = 0; i < 5; i++) 
    {
        if (fscanf(Ip, "%d", &a[i]) != 1) 
        {
            printf("정수 %d번째를 읽지 못했습니다. (프로그램 종료)\n", i + 1);
            fclose(Ip);
            return 0;
        }
    }
    fclose(Ip);
    return 1;
}
// 배열애 값을 저장
int arr_save(FILE *Ip, FILE *Op, int a[5])
{
    for(int i = 0; i < 5; i++) 
    {
        if(fscanf(Op, "%d", &a[i]) != 1) 
        {
            printf("정수 %d번째를 읽지 못했습니다. (프로그램 종료)\n", i+1);

            fclose(Op);

            fclose(Ip);

            return 0;
        }
        printf("파일에서 정수 %d 개를 읽었습니다\n", i+1);
    }
}
// 파일로 저장
int file_save(FILE *Op, int a[5])
{
    sort(a,5,UP);

    for(int i = 0; i < 5; i++) 
    {
        fprintf(Op, "%d = [%d]\n", i+1, a[i]);
    }
    printf("파일에 자료를 출력하였습니다");
}

int main() 
{
    char Input_name[100], Output_name[100];
    int a[5];
    FILE *Ip = NULL, *Op = NULL;

    // 파일 이름 입력
    file_name(Input_name, Output_name);

    // 입력 파일 열기
    if (!file_open(Input_name, &Ip)) 
    {
        return 1;
    }

    // 입력 파일에서 정수 5개 읽기
    if (!file_output(Ip, a)) 
    {
        return 1;
    }

    // 읽은 값 출력
    printf("입력한 정수들: ");
    for (int i = 0; i < 5; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    // 출력 파일 열기
    Op = fopen(Output_name, "w");
    if (Op == NULL) 
    {
        printf("출력 파일 [%s] 열기 실패했습니다.\n", Output_name);
        return 1;
    }

    // 정렬 후 출력 파일에 저장
    if (!file_save(Op, a)) 
    {
        return 1;
    }

    printf("프로그램을 정상적으로 종료합니다.\n");
    return 0;
}