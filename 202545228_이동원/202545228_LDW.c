#include <stdio.h>
#include <time.h>
#include <string.h>

/*
(1) 프로그램이 실행되면 처리할 자료가 저장된 파일명을 입력한다.
(*단, 몇 명의 자료가 저장되어 있는지는 파일을 읽어보아야 알 수 있다.)
(2) 다 읽고 나면 몇 명의 자료를 읽었는지 확인 메시지를 출력한다.
(3) 각 학생들의 합계와 평균을 계산한다.
(4) 합계를 기준으로 학생들의 석차를 계산한다. 합계가 같으면 같은 석차로 처리한다.
(처리 예: 1등이 1명, 2등이 2명이면 다음 등수는 4등부터 시작한다.)
(5) 종합성적 일람표 출력 조건:
- 한 줄에 학생의 성명, 국어, 영어, 수학, 합계, 평균, 석차 표시
- 상단에는 칼럼별 제목 표시
- 하단에는 과목별 평균, 전체 평균을 표시
(6) 개인별 성적표 출력 조건:
- 성명, 국어, 영어, 수학, 합계, 평균, 개인별 석차
(7) *위의 단계가 진행될 때마다 적절한 진행상황을 알 수 있는 메시지를 화면에 출력한다.
(8) 모든 출력파일 마지막에는 프로그램 작성자 학번, 이름과 성적처리 일시를 출력한다
*/

#define STUDENT 100
#define NAME 20

typedef struct {
    char name[NAME];
    int kor;
    int eng;
    int math;
    int sum;
    double avg;
    int rank;
} Student;

//프로그램이 실행되면 처리할 자료가 저장된 파일명을 입력한다.
void FILENAME(char *filename)
{
    printf("성적 관리를 원하시는 파일 명을 입력하세요 : ");
    scanf("%s", filename);
}

//다 읽고 나면 몇 명의 자료를 읽었는지 확인 메시지를 출력한다.
void STUDENT_COUNT(int student_count)
{
    printf("학생 수 확인 시작\n");
    
    printf("%d명 의 학생이 있습니다", student_count);
}

//각 학생들의 합계와 평균을 계산한다.
void STUDENT_SUM_AVERAGE(Student student[], int count)
{
    printf("합계, 평균 계산 시작\n");

    for(int i = 0; i < count; i++)
    {
        student[i].sum = student[i].kor + student[i].eng + student[i].math;

        student[i].avg = student[i].sum / 3.0;
    }
}

//합계를 기준으로 학생들의 석차를 계산한다. 합계가 같으면 같은 석차로 처리한다.
void RANK(int sum_scores[], int student_count, int rank[])
{
    printf("석차 계산 시작\n");

    for(int i = 0; i < student_count; i++)
    {
        rank[i] = 1;
        
        for(int j = 0; j < student_count; j++)
        {
            if(sum_scores[j] > sum_scores[i])
            {
                rank[i]++;
            }
        }
    }
    printf("석차 계산 완료\n");
}

//개인 성적 일람표 출력
void PRINT_FILE_SOLO(Student student[], int count, char filename[])
{
    char name[NAME];

    printf("개인 성적 일람표 출력할 학생 이름을 입력하세요 : \n");

    scanf("%s", name);
    sprintf(filename, "%s_의 개인 성적표", name);

    FILE *file = fopen(filename, "w");

    if(file == NULL)
    {
        printf("개인 성적 일람표 파일 출력 오류\n");
        return;
    }

    fprintf(file, "성명\t국어\t영어\t수학\t합계\t평균\t석차\n");

    int STUDENT_TRUE = 0;

    for(int i = 0; i < count; i++)
    {
        if(strcmp(student[i].name, name) == 0)
        {
            fprintf(file, "%s\t%d\t%d\t%d\t%d\t%.1f\t%d\n",
            student[i].name,
            student[i].kor,
            student[i].eng,
            student[i].math,
            student[i].sum,
            student[i].avg,
            student[i].rank
            );

            STUDENT_TRUE = 1;
        }
    }

    if(!STUDENT_TRUE)
    {
        printf("일치 하는 학생명이 없습니다.\n");
    }

    time_t now;
    time(&now);

    fprintf(file, "\nㅡㅡㅡㅡㅡ\n");
    fprintf(file, "작 성 자 : 202545228 이동원\n");
    fprintf(file, "출력 일시 : %s", ctime(&now));

    fclose(file);

    printf("의 개인 성적 일람표가 %s 파일로 저장 되었습니다", filename);
}

//종합 성적 일람표 출력
void PRINT_FILE_ALL(Student student[], int count, char filename[])
{
    FILE *file = fopen(filename, "w");
    
    if(file == NULL)
    {
        printf("종합 성적 일람표 출력 오류\n");
        return;
    }

    printf("종합 성적 일람표를 출력 합니다\n");

    fprintf(file, "성명\t국어\t영어\t수학\t합계\t평균\t석차\n");

    for(int i = 0; i < count; i++)
    {
        fprintf(file, "%s\t%d\t%d\t%d\t%d\t%.1f\t%d\n",
        student[i].name,
        student[i].kor,
        student[i].eng,
        student[i].math,
        student[i].sum,
        student[i].avg,
        student[i].rank
        );
    }

    int kor_sum = 0, eng_sum = 0, math_sum = 0;

    for(int i = 0; i < count; i++)
    {
        kor_sum += student[i].kor;
        eng_sum += student[i].eng;
        math_sum += student[i].math;
    }

    double kor_avg = (double)kor_sum/count;
    double eng_avg = (double)eng_sum/count;
    double math_avg = (double)math_sum/count;
    double total_avg = (kor_avg + eng_avg + math_avg) / 3;

    fprintf(file, "\nㅡㅡㅡㅡㅡ\n");
    fprintf(file, "국어 평균: %.1f\n", kor_avg);
    fprintf(file, "영어 평균: %.1f\n", eng_avg);
    fprintf(file, "수학 평균: %.1f\n", math_avg);
    fprintf(file, "전체 평균: %.1f\n", total_avg);

    time_t now;
    time(&now);

    fprintf(file, "\nㅡㅡㅡㅡㅡ\n");
    fprintf(file, "작 성 자 : 202545228 이동원\n");
    fprintf(file, "출력 일시 : %s", ctime(&now));

    fclose(file);

    printf("종합 성적 일람표가 %s 파일로 저장 되었습니다", filename);
}

int main()
{
    Student student[STUDENT];
    char filename[NAME];
    int count = 0;
    int num = 0;
    int sum_scores[STUDENT];
    int rank[STUDENT];
    char name[NAME];

    //파일명 입력
    FILENAME(filename);
    printf("파일을 읽고 있습니다\n");

    //데이터 읽기
    printf("데이터 확인 시작\n");

    FILE *fp = fopen(filename, "r");
    if(fp == NULL) 
    {
        printf("파일을 읽을 수 없습니다.\n");
        return 1;
    }
    
    while(fscanf(fp, "%s %d %d %d", student[count].name, &student[count].kor, &student[count].eng, &student[count].math) == 4) 
    {
        count++;
        if(count >= STUDENT) break;
    }

    fclose(fp);

    //학생 수 확인
    STUDENT_COUNT(count);

    //합계 평균 계산
    STUDENT_SUM_AVERAGE(student, count);
    
    //석차 계산
    for(int i = 0; i < count; i++)
    {
        sum_scores[i] = student[i].sum;
    }

    RANK(sum_scores, count, rank);

    for(int i = 0; i < count; i++)
    {
        student[i].rank = rank[i];
    }
    
    //성적 출력 방식 선택
    printf("개인 성적 일람표 출력 : 0 \n종합 성적 일람표 출력 : 1\n");
    scanf("%d", &num);

    if(num == 0)
    {
        PRINT_FILE_SOLO(student, count, "%d 개인성적표.txt");
    }
    else if(num == 1)
    {
        PRINT_FILE_ALL(student, count, "종합성적표.txt");
    }
    else
    {
        printf("0 과 1 중 선택 해주세요");
        return 1;
    }
}