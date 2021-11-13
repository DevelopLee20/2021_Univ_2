#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Queue.h"

#define SIZE 10 // 정렬할 개수
#define RANGE 100 // 배열 개수 랜덤 배열 최대 범위 (1 ~ RANGE)
#define BUCKETS 10  // 자리수 구분
#define DIGITS 3 // 자리수
#define SIZE 10  // 개수

void rand_Array(int list[]){ // 랜덤 배열 생성
    srand(time(NULL));

    for(int i=0; i<SIZE; i++){
        list[i] = (rand()%RANGE)+1;
    }
}

void print_bucket(QueueType q[]){
    printf("==========================\n");
    for(int i=0; i<BUCKETS; i++){
        QueueType qq = q[i];
        printf("[%d]-> ",i);
        while(!is_empty(&qq)){
            printf("%d ",dequeue(&qq));
        }
        printf("\n");
    }
    printf("==========================");
}

void radix_sort(int list[], int n){
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];

    for(b=0; b<BUCKETS; b++){
        init_queue(&queues[b]);
    }

    for(d=0; d<DIGITS; d++){
        for(i=0; i<n; i++){
            enqueue(&queues[(list[i]/factor)%10], list[i]);
        }
        print_bucket(queues);
        for(b=i=0; b<BUCKETS; b++){
            while(!is_empty(&queues[b])){
                list[i++] = dequeue(&queues[b]);
            }
        }
        printf("\n");
        factor *= 10;
    }
}

int main(void){
    int list[SIZE];

    rand_Array(list);

    radix_sort(list, SIZE);

    return 0;
}