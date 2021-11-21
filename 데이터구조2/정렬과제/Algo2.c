#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) // 버블정렬, 선택정렬, 퀵정렬
#define SIZE 1000 // 정렬할 개수
#define RANGE 1000000 // 배열 개수 랜덤 배열 최대 범위 (1 ~ RANGE)

// 랜덤 배열 생성
void rand_Array(int list[]){
    srand(time(NULL));

    for(int i=0; i<SIZE; i++){
        list[i] = (rand()%RANGE)+1;
        for(int j=0; j<i; j++){
            if(list[i] == list[j]){
                i--;
            }
        }
    }
}

// 버블 정렬
void bubble_sort(int list[], int n){
    int temp;

    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(list[j]>list[j+1]){
                SWAP(list[j], list[j+1], temp);
            }
        }
    }
}

// 선택 정렬
void selection_sort(int list[], int n){
    int least, temp;

    for(int i=0; i<n-1; i++){
        least = i;
        for(int j=i+1; j<n; j++){
            if(list[j] < list[least]){
                least = j;
            }
        }
        SWAP(list[i], list[least], temp);
    }
}

// 삽입 정렬
void insertion_sort(int list[], int n){
    int j, key;

    for(int i=1; i<n; i++){
        key = list[i];
        
        for(j=i-1; j>=0 && list[j]>key; j--){
            list[j+1] = list[j];
        }
        list[j+1] = key;
    }
}

// 쉘 정렬용
void inc_insertion_sort(int list[], int first, int last, int gap){
    int i, j, key;

    for(int i=first+gap; i<=last; i=i+gap){
        key = list[i];

        for(j=i-gap; j>=first && key<list[j]; j=j-gap){
            list[j+gap] = list[j];
        }
        list[j+gap] = key;
    }
}

// 쉘 정렬
void shell_sort(int list[], int n){
    int i, gap;
    for(int gap=n/2; gap>0; gap=gap/2){
        if((gap%2) == 0) gap++;
        for(i=0; i<gap; i++){
            inc_insertion_sort(list, i, n-1, gap);
        }
    }
}

// 선택 정렬 테스트
void test_selection(){
    int list[SIZE];

    rand_Array(list);

    selection_sort(list, SIZE);
}

// 버블 정렬 테스트
void test_bubble(){
    int list[SIZE];

    rand_Array(list);

    bubble_sort(list, SIZE);
}

// 삽입정렬 테스트
void test_insertion(){
    int list[SIZE];

    rand_Array(list);

    insertion_sort(list, SIZE);
}

// 쉘 정렬 테스트
void test_shell(){
    int list[SIZE];

    rand_Array(list);

    shell_sort(list, SIZE);
}

int main(void){
    clock_t start, end;
    
    start = clock();
    test_bubble();
    end = clock();
    printf("버블정렬 소요시간: %.4lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    printf("\n");

    start = clock();
    test_selection();
    end = clock();
    printf("선택정렬 소요시간: %.4lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    printf("\n");

    start = clock();
    test_insertion();
    end = clock();
    printf("삽입정렬 소요시간: %.4lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    printf("\n");

    start = clock();
    test_shell();
    end = clock();
    printf("셀정렬 소요시간: %.4lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}