#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000 // 정렬할 개수
#define RANGE 1000000 // 배열 개수 랜덤 배열 최대 범위 (1 ~ RANGE)
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))   // 퀵정렬용 스왑
#define MAX_QUEUE_SIZE 1001  // 기수정렬 큐
#define BUCKETS 10  // 기수정렬 저장
#define DIGITS 7    // 기수정렬 자리수

int sorted[SIZE];   // 합병정렬 정리된 배열

///////////////////////// 큐 자료형 전용 /////////////////////////

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

///////////////////////// 큐 자료형 전용 /////////////////////////

void radix_sort(int list[], int n){ // 기수정렬
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];

    for(b=0; b<BUCKETS; b++){
        init_queue(&queues[b]);
    }

    for(d=0; d<DIGITS; d++){
        for(i=0; i<n; i++){
            enqueue(&queues[(list[i]/factor)%10], list[i]);
        }
        for(b=i=0; b<BUCKETS; b++){
            while(!is_empty(&queues[b])){
                list[i++] = dequeue(&queues[b]);
            }
        }
        factor *= 10;
    }
}

void merge(int list[], int left, int mid, int right){   // 합병정렬
    int i, j, k, l;
    i = left; j = mid + 1; k = left;

    while(i<=mid && j<=right){
        if(list[i] <= list[j]){
            sorted[k++] = list[i++];
        }
        else{
            sorted[k++] = list[j++];
        }
    }
    if(i>mid){
        for(l=j; l<=right; l++){
            sorted[k++] = list[l];
        }
    }
    else{
        for(l=i; l<=mid; l++){
            sorted[k++] = list[l];
        }
    }
    for(l=left; l<=right; l++){
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right){   // 합병정렬
    int mid;

    if(left<right){
        mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}

void rand_Array(int list[]){ // 랜덤 배열 생성
    srand(time(NULL));

    for(int i=0; i<SIZE; i++){
        list[i] = (rand()%RANGE)+1;
    }
}

void print_Array(int list[]){   // 배열 상태 출력
    for(int i=0; i<SIZE; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
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

        if(low<high) SWAP(list[low],list[high],temp);
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

void merge_test(void){  // 합병정렬 테스트
    int list[SIZE];

    rand_Array(list);

    merge_sort(list,0,SIZE-1);

    // print_Array(list);
}

void quick_test(void){  // 퀵정렬 테스트
    int list[SIZE];

    rand_Array(list);

    quick_sort(list,0,SIZE-1);

    // print_Array(list);
}

void radix_test(void){  // 기수정렬 테스트
    int list[SIZE];

    rand_Array(list);

    radix_sort(list, SIZE);

    // print_Array(list);
}

int main(void){
    clock_t start, end;

    start = clock();
    merge_test();
    end = clock();
    printf("합병정렬 소요시간: %.8lf\n",(double)(end-start)/CLOCKS_PER_SEC);
    start = clock();
    quick_test();
    printf(" 퀵정렬 소요시간: %.8lf\n",(double)(end-start)/CLOCKS_PER_SEC);
    start = clock();
    radix_test();
    printf("기수정렬 소요시간: %.8lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}