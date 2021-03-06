#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100
#define BUCKETS 10
#define DIGITS 3 // 자리수
#define SIZE 10  // 개수
typedef int element;

typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q){
    q->front = q->rear = 0;
}

int is_empty(QueueType *q){
    return (q->front == q->rear);
}

int is_full(QueueType *q){
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item){
    if(is_full(q)){
        error("큐가 포화상태입니다.");
    }
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void radix_sort(int list[], int n){
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];

    for(b=0; b<BUCKETS; b++){
        init_queue(&queues[b]);
    }

    for(d=0; d<DIGITS; d++){
        for(i=0; i<n; i++){
            printf("queues[%d]:%d, ", list[i]/factor%10, list[i]);
            enqueue(&queues[(list[i]/factor)%10], list[i]);
        }
        printf("\n");
        for(b=i=0; b<BUCKETS; b++){
            while(!is_empty(&queues[b])){
                list[i++] = dequeue(&queues[b]);
                printf("dequeue[%d]:%d, ", b, list[i-1]);
            }
        }
        printf("\n");
        factor *= 10;
    }
}

int main(void){
    int list[SIZE] = {123,398,210,409,528,003,513,129,220,294};
    // srand(time(NULL));

    // for(int i=0; i<SIZE; i++){
    //     list[i] = rand() % 100;
    // }

    radix_sort(list, SIZE);

    for(int i=0; i<SIZE; i++){
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}