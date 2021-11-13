#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // 정렬할 개수
#define RANGE 100 // 배열 개수 랜덤 배열 최대 범위 (1 ~ RANGE)
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))   // 퀵정렬용 스왑

void rand_Array(int list[]){ // 랜덤 배열 생성
    srand(time(NULL));

    for(int i=0; i<SIZE; i++){
        list[i] = (rand()%RANGE)+1;
    }
}

int partition(int list[], int left, int right){ // 퀵정렬
    int pivot, temp;
    int low, high;

    low = left;
    high = right+1;
    pivot = list[left];
    do{
        do{
            low++;
        } while(list[low]<pivot);

        do{
            high--;
        } while(list[high]>pivot);

        if(low<high){
            for(int i=0; i<SIZE; i++){
                ///// 수정한 내용 /////
                if(i == low){
                    printf("(low)");
                }
                else if(i == high){
                    printf("(high)");
                }
                printf("%d ", list[i]);
                ///// 수정한 내용 /////
            }
            printf("\n");
            SWAP(list[low],list[high],temp);
        }
    } while(low<high);

    SWAP(list[left], list[high], temp);

    return high;
}

void quick_sort(int list[], int left, int right){   // 퀵정렬
    if(left<right){
        int q = partition(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
}

void quick_test(){  // 퀵정렬 테스트
    int list[SIZE];

    rand_Array(list);

    quick_sort(list,0,SIZE-1);

    printf("정렬된 배열: ");
    for(int i=0; i<SIZE; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main(void){
    quick_test();

    return 0;
}