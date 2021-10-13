// 과제 낼때 예제를 스스로 만들어서 제출하는 것도 좋다.

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100 // 2-1 조건. Heap의 최대크기는 100으로 정한다.

// MAX heap 구현
typedef struct{
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// MAX heap 생성
HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

// MAX heap 초기화
void init(HeapType* h){
    h->heap_size = 0;
}

// 연산의 종류 1. 삽입
void insert_max_heap(HeapType* h, element item){
    int i;

<<<<<<< HEAD
    if (h->heap_size >= MAX_ELEMENT){
=======
    // 모두 차 있는 경우 Full
    if (h->heap_size == 100){
>>>>>>> 6ded01e15177fd09d8a59f543dc1b5bf37ede25b
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

// 연산의 종류 2. 삭제후 출력
element delete_max_heap(HeapType* h){
    int parent, child;
    element item, temp;

<<<<<<< HEAD
    if (h->heap_size <= 0){
=======
    // 비어있는 경우 Empty
    if (h->heap_size == 0){
>>>>>>> 6ded01e15177fd09d8a59f543dc1b5bf37ede25b
        printf("Empty\n");
    }

    else{
<<<<<<< HEAD
        item = h->heap[1];                // 최상단 노드
=======
        item = h->heap[1]; // 최상단 노드
>>>>>>> 6ded01e15177fd09d8a59f543dc1b5bf37ede25b
        temp = h->heap[(h->heap_size)--]; // 말단 노드
        parent = 1;
        child = 2;
        
        // 비교가 자식 노드의 왼쪽 오른쪽을 비교하는게 아니라 그냥 1부터 차례로 비교함
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
        printf("%d\n", item);
    }
}

// 메인 함수
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
            delete_max_heap(heap);
        }
        else if (command == 'Q'){
            break;
        }
    }
    return 0;
}