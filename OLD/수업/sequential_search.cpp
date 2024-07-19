#define FIND_NUM 6896383 //찾고 싶은 데이터

#include <iostream>
#include <ctime>

using namespace std;

int main() {
    clock_t start, stop = 0; // 코드 동작 시간 계산을 위해 선언
    double result = 0; // 코드 동작 시간 계산을 위해 선언
    start = clock(); // 동작 시작

    FILE* fp = fopen("./1.in", "r"); //상대경로로 파일 찾기
    if(fp == NULL) return -1; //못찾으면 종료

    while(!feof(fp)){ //파일의 끝이면 while문 종료
        int temp; //읽은 데이터 저장하기 위해 변수 선언
        fscanf(fp, "%d", &temp); //파일에서 읽어와 데이터 저장
        if(temp == FIND_NUM)break; //찾는 데이터랑 같으면 while문 종료

    }
    stop = clock();//동작 끝

    result = (double)(stop-start) / CLOCKS_PER_SEC; //시간 계산
    printf("걸린 시간은 %f초입니다.", result);
    fclose(fp);
    return 0;
}