#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

typedef struct{
    int key;
} element;

typedef struct{
    element binarytree[MAX_SIZE];
    int size;
} HeapType;

HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType *q){
    q->size = 0;
}

int is_empty(HeapType *q){
    return (q->size == 0);
}

int is_full(HeapType *q){
    return (q->size == 50);
}

void insert(HeapType *q, int x){
    q->binarytree[++(q->size)].key = x;

    int child = q->size;
    int parent = child/2;

    while(q->binarytree[child].key > q->binarytree[parent].key && child != 1){
        int temp = q->binarytree[child].key;
        q->binarytree[child].key = q->binarytree[parent].key;
        q->binarytree[parent].key = temp;

        child = parent;
        parent = child/2;
    }
}

int delete(HeapType *q){
    int rturn = q->binarytree[1].key;
    q->binarytree[1].key = q->binarytree[q->size--].key;

    int parent = 1;
    int child = parent*2;

    while(child <= q->size){
        if(q->binarytree[parent].key < q->binarytree[child].key && q->binarytree[child].key > q->binarytree[child].key){
            int temp = q->binarytree[child].key;
            q->binarytree[child].key = q->binarytree[parent].key;
            q->binarytree[parent].key = temp;
            parent = child;
            child = parent*2;
        }
        else if(q->binarytree[parent].key < q->binarytree[child+1].key && q->binarytree[child].key < q->binarytree[child].key){
            int temp = q->binarytree[child+1].key;
            q->binarytree[child+1].key = q->binarytree[parent].key;
            q->binarytree[parent].key = temp;
            parent = child+1;
            child = parent*2;
        }
        else{
            break;
        }
    }
    return rturn;
}

void find(HeapType *q){
    return;
}

int main(void){
    int e1 = 10, e2 = 5, e3 = 30;
    int e4, e5, e6;

    HeapType *heap = create();
    init(heap);

    insert(heap, e1);
    insert(heap, e2);
    insert(heap, e3);

    e4 = delete(heap);
    printf("< %d > ", e4);
    e5 = delete(heap);
    printf("< %d > ", e5);
    e6 = delete(heap);
    printf("< %d > \n", e6);

    free(heap);

    return 0;
}