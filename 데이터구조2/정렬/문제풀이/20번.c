////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define SIZE 10

typedef struct{
    int key;
} element;

typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType *h){
    h->heap_size = 0;
}

void insert_max_heap(HeapType *h, element item){
    int i;
    i = ++(h->heap_size);

    // h->head[i/2].key = 부모꺼 i까지 오면 최상단이므로 종료 결국 최종적으로 1이 되게 되어있음 2/2 = 1, 3/2 = 1
    while((i!=1) && (item.key > h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2];  // 덮어쓰기로 아래부터 차례로 덮어씀
        i /= 2;
    }
    h->heap[i] = item;              // 결과값을 마지막에 반환

    for(int i=1; i<h->heap_size; i++){
        printf("%d ",h->heap[i]);
    }
    printf("\n");
}

element delete_max_heap(HeapType *h){
    int parent, child;
    element item, temp;

    item = h->heap[1];                  // 최상단 item에 저장 (삭제할 위치)
    temp = h->heap[(h->heap_size)--];   // 말단 temp에 저장
    parent = 1;                         // 부모 노드의 인덱스는 1
    child = 2;                          // 자식 노드의 인덱스는 2

    while(child <= h->heap_size){       // 자식 노드가 힙사이즈에서 벗어나면 종료
        // 자식노드가 힙사이즈에 벗어나지 않게(child++연산까지 가능하도록), 왼쪽과 오른쪽 중 큰 값이 오른쪽이면 자식노드를 오른쪽으로 이동
        if((child < h->heap_size) && (h->heap[child].key < h->heap[child+1].key)){
            child++;
        }
        
        // 말단 키값이 트리의 노드보다 크면 거기에 삽입하기 위해서 종료
        if(temp.key >= h->heap[child].key){
            break;
        }
        
        h->heap[parent] = h->heap[child]; // 위에 값을 아래꺼랑 복사해서 점점 내려간다
        parent = child;                   // parent = child로 자식 노드로 입장
        child *= 2;                       // 자식노드는 자식의 자식으로 입장
    }
    h->heap[parent] = temp; // 위치가 정해지면 그 위치에 temp 값을 삽입, 원래 있던애는 진작에 복사되어있음

    return item; // 삭제한 거 반환
}

void heap_sort(element a[], int n){

    HeapType *h = create();
    init(h);

    for(int i=0; i<n; i++){
        // printf("%d ",a[i]);
        insert_max_heap(h, a[i]);
    }
    for(int i=(n-1); i >= 0; i--){
        a[i] = delete_max_heap(h);
    }
    free(h);
}

int main(void){
    element list[SIZE] = {41,67,34,0,69,24,78,58,62,64};
    heap_sort(list, SIZE);
    return 0;
}
////////////////////////////////////////////////////////