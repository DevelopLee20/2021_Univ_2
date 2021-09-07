// 과제 낼때 예제를 스스로 만들어서 제출하는 것도 좋다.

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct{
    int key;
} element;
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h){
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item){

    int i;

    // 조건 수정
    if (h->heap_size == 100){
        printf("Full\n");
    }
    else{
        i = ++(h->heap_size);

        while((i != 1) && (item.key > h->heap[i/2].key)){
            h->heap[i] = h->heap[i/2];
            i /= 2;
        }
        h->heap[i] = item;
    }

}

element delete_max_heap(HeapType* h){
    int parent, child;
    element item, temp;

    if (h->heap_size == 0){
        printf("Empty\n");
    }

    else{
        item = h->heap[1];
        temp = h->heap[(h->heap_size)--];
        parent = 1;
        child = 2;
        
        while (child <= h->heap_size){
            if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child+1].key){
                child++;
            }
            if (temp.key >= h->heap[child].key){
                break;
            }
            h->heap[parent] = h->heap[child];
            parent = child;
            child *= 2;
        }
        h->heap[parent] = temp;
        return item;   
    }
}

int main(void){
    HeapType* heap;

    heap = create();
    init(heap);

    while(1){
        char command;
        element num;

        scanf("%c", &command);

        if (command == 'I'){
            scanf("%d", &num);
            insert_max_heap(heap, num);
        }
        else if (command == 'D'){
            delete_max_heap(heap).keys
            if( != 'None'){
                printf("%d\n", );
            }
        }
        else if (command == 'Q'){
            break;
        }
    }
    return 0;
}