#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100
#define BUCKETS 10
#define DIGITS 3
#define SIZE 1000
#define RANGE 100
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef int element;
int sorted[SIZE];

typedef struct{ // 기수 정렬용
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message){ // 에러 출력 함수
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q){ // 기수 정렬용
    q->front = q->rear = 0;
}

int is_empty(QueueType *q){
    return (q->front == q->rear);
}

int is_full(QueueType *q){
    return ((q->rear+1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item){
    if(is_full(q)){
        error("큐가 포화상태입니다.");
    }
    q->rear = (q->rear+1) & MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    q->front = (q->front+1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int rand_Array(int list[]){
    srand(time(NULL));

    for(int i=0; i<SIZE; i++){
        list[i] = (rand() % RANGE)+1;
    }
}

void print_Array(int list[]){
    for(int i=0; i<SIZE; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}

void radix_sort(int list[], int n){
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];

    for(b=0; b<BUCKETS; b++){
        init_queue(&queues[b]);
    }

    for(d=0; d<DIGITS; d++){
        for(int i=0; i<n; i++){
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

void test_GiSu(void){
    
    int list[SIZE];

    rand_Array(list);

    radix_sort(list, SIZE);
    
    print_Array(list);
}

int partition(int list[], int left, int right){
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

void quick_sort(int list[], int left, int right){
    if(left<right){
        int q = partition(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
}

void test_quick(void){
    int list[SIZE];
    
    rand_Array(list);

    quick_sort(list,0,SIZE-1);

    print_Array(list);
}

void merge(int list[], int left, int mid, int right){
    int i, j, k, l;
    i=left; j=mid+1; k=left;

    while(i<=mid && j<=right){
        if(list[i]<=list[j]){
            sorted[k++] = list[j++];
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
        for(l=i; l<=right; l++){
            sorted[k++] = list[l];
        }
    }

    for(l=left; l<=right; l++){
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right){
    int mid;

    if(left<right){
        mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}

void test_merge(void){
    int list[SIZE];

    rand_Array(list);

    merge_sort(list, 0, 0);

    print_Array(list);
}

int main(void){

    clock_t start, end;

    start = clock();
    test_GiSu();
    end = clock();
    printf("GiSu: %.7lf\n",(double)(end-start)/CLOCKS_PER_SEC);
    start = clock();
    test_quick();
    end = clock();
    printf("quick: %.7lf\n",(double)(end-start)/CLOCKS_PER_SEC);
    start = clock();
    test_merge();
    end = clock();
    printf("merge: %.7lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}