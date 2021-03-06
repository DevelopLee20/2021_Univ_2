#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;

#define MAX_QUEUE_SIZE 100
#define BUCKETS 10
#define DIGITS 3 // 자리수
#define SIZE 10  // 개수

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