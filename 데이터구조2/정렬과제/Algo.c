#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) // 버블정렬, 선택정렬, 퀵정렬
#define SIZE 10 // 정렬할 개수
#define RANGE 100 // 배열 개수 랜덤 배열 최대 범위 (1 ~ RANGE)

int num = 1;

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

// Step 배열 출력
void print_array_with_name(int list[], char *text, int n){
    printf("%s %d: ",text, n);
    for(int i=0; i<SIZE; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}

// 배열 출력
void print_array(int list[]){
    for(int i=0; i<SIZE; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
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
        print_array_with_name(list,"Step  ",num++);
    }
    num = 1;
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
        print_array_with_name(list,"Step  ",num++);
    }
    num = 1;
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
        print_array_with_name(list,"Step  ",num++);
    }
    num = 1;
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
        print_array_with_name(list,"Step: ",num++);
    }
    num = 1;
}

// 선택 정렬 테스트
void test_selection(){
    int list[SIZE];

    rand_Array(list);

    printf("선택 정렬\n");

    printf("입력데이터: ");
    print_array(list);

    selection_sort(list, SIZE);

    printf("정렬데이터: ");
    print_array(list);
}

// 버블 정렬 테스트
void test_bubble(){
    int list[SIZE];

    rand_Array(list);

    printf("버블 정렬\n");

    printf("입력데이터: ");
    print_array(list);

    bubble_sort(list, SIZE);

    printf("정렬데이터: ");
    print_array(list);
}

// 삽입정렬 테스트
void test_insertion(){
    int list[SIZE];

    rand_Array(list);

    printf("삽입 정렬\n");

    printf("입력데이터: ");
    print_array(list);

    insertion_sort(list, SIZE);

    printf("정렬데이터: ");
    print_array(list);
}

// 쉘 정렬 테스트
void test_shell(){
    int list[SIZE];

    rand_Array(list);

    printf("쉘 정렬\n");

    printf("입력데이터: ");
    print_array(list);

    shell_sort(list, SIZE);

    printf("정렬데이터: ");
    print_array(list);
}

int main(void){
    test_bubble();
    printf("\n");
    test_selection();
    printf("\n");
    test_insertion();
    printf("\n");
    test_shell();

    return 0;
}