#include <stdio.h>
#include <stdlib.h>
#define MIN_ELEMENT 200

typedef struct{
    int key;
} element;
typedef struct {
    element heap[MIN_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h){
    h->heap_size = 0;
}

void insert_min_heap(HeapType* h, element item){
    int i;
    i = ++(h->heap_size);

    while((i != 1) && (item.key < h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_min_heap(HeapType* h){
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    
    while (child <= h->heap_size){
        if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child+1].key){
            child++;
        }
        if (temp.key <= h->heap[child].key){
            break;
        }
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;   
}

// 과제 내용
element delete_choice(HeapType* h, element item){
    element temp;
    for(int i=1; i<h->heap_size; i++){
        if (h->heap[i].key == item.key){
            temp = h->heap[i];
            h->heap[i] = h->heap[1];
            h->heap[1] = temp;
            break;
        }
    }
    delete_min_heap(h);
    return temp;
}

int main(void){
    element e1 = {10}, e2 = {5}, e3 = {30};
    element e4, e5, e6;
    HeapType* heap;

    heap = create();
    init(heap);

    insert_min_heap(heap, e1);
    insert_min_heap(heap, e2);
    insert_min_heap(heap, e3);

    e4 = delete_choice(heap, e1);
    printf("< %d > ", e4.key);
    e5 = delete_min_heap(heap);
    printf("< %d > ", e5.key);
    e6 = delete_min_heap(heap);
    printf("< %d > ", e6.key);

    free(heap);

    return 0;
}