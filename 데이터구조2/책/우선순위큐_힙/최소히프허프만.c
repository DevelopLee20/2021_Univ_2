#include <stdio.h>          // 표준 입출력
#include <stdlib.h>         // malloc 사용
#define MAX_ELEMENT 200     // 최대 히프 200 설정

typedef struct TreeNode{        // TreeNode 선언
    int weight;                 // int weight 선언 w가 저장됨
    char ch;                    // char ch 선언 문자 하나 저장
    struct TreeNode *left;      // 왼쪽 자식 트리
    struct TreeNode *right;     // 오른쪽 자식 트리
} TreeNode;                     // TreeNode를 TreeNode로 선언하면 구조체 내에서 사용 가능

typedef struct{         // 구조체 선언(Heap에서 쓸거임)
    TreeNode *ptree;    // TreeNode의 구조체를 가진 ptree 선언(모든 트리의 헤드)
    char ch;            // 문자 하나 저장함(element로 선언되어있어서 데이터형? 인듯)
    int key;            // key 또한 데이터형? 인듯
} element;              // element로 선언되어있음(데이터형임)

typedef struct{                 // Heap구조체 선언
    element heap[MAX_ELEMENT];  // Heap 구조체에는 element 라는 힙 구조를 저장하는 배열이 저장되어있음
    int heap_size;              // Heap의 크기를 저장할 변수
} HeapType;                     // HeapType으로 선언

HeapType *create(){                             // HeapType의 구조체를 malloc으로 동적 생성함
    return (HeapType*)malloc(sizeof(HeapType)); // 동적 생성해서 반환함(굳이 필요한지는 모름;;)
}

void init(HeapType *h){ // HeapType 초기화
    h->heap_size = 0;   // heap_size = 0 으로 힙 초기화
}

void insert_min_heap(HeapType *h, element item){        // 최소 힙 삽입
    int i = ++(h->heap_size);                           // heap size를 1 증가

    while((i != 1) && (item.key < h->heap[i/2].key)){   // 힙이 1개가 아닐때 즉 1개 이상일때, item의 key 값과 비교해서 자식이 더 클때까지
        h->heap[i] = h->heap[i/2];                      // 부모가 자식 노드가 된다.
        i /= 2;                                         // 자식 노드로 들어가기
    }
    h->heap[i] = item;                                  // 그 위치에 item 삽입
}

element delete_min_heap(HeapType *h){   // 최소 힙 제거
    int parent, child;                  // 부모 노드와 자식 노드
    element item, temp;                 // item 저장하고, temp 저장

    item = h->heap[1];                  // item 은 최상단에 있는 item 저장
    temp = h->heap[(h->heap_size)--];   // temp 값은 가장 말단 노드가 됨
    parent = 1;                         // 부모 노드는 현재 1번지를 가리키고 있음
    child = 2;                          // 자식 노드는 현재 2번지를 가리키고 있음

    while(child <= h->heap_size){   // 자식 노드가 더 이상 없을 경우 -> child가 heap_size를 벗어남
        // 왼쪽 노드로 갈지 오른쪽 노드로 갈지 결정
        if((child <= h->heap_size) && (h->heap[child].key) > h->heap[child+1].key){
            child++;    // child 값을 1 증가시킴
        }

        // 조건을 만족해서 break 최소가 맨 위로 가는 조건 성립됨
        if(temp.key < h->heap[child].key){
            break;
        }

        h->heap[parent] = h->heap[child];   // 바꾸어줌..? (모르겠다)
        parent = child;                     // 부모 노드가 자식이 되면서 하나 내려감
        child *= 2;                         // 자식 노드의 자식으로 내려감
    }
    h->heap[parent] = temp;                 // 현재 위치에 대입
    
    return item;                            // item 반환
}

TreeNode *make_tree(TreeNode *left, TreeNode *right){       // tree를 만들어서 포인터를 반환함
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));   // 동적 생성

    node->left = left;      // 왼쪽 노드
    node->right = right;    // 오른쪽 노드
    
    return node;            // 노드 반환
}

void destory_tree(TreeNode *root){  // 트리 파괴
    if(root == NULL){               // 포인터를 삭제되어있음을 확인
        return;                    
    }

    destory_tree(root->left);   // 왼쪽 노드 파괴
    destory_tree(root->right);  // 오른쪽 노드 파괴
    free(root);                 // 현재 노드 파괴
}                               // 결국 재귀 함수 형태로 하나씩 모두가 삭제됨

int is_leaf(TreeNode *root){                // 잎 노드인지 확인(잎 노드는 자식 노드가 없다)
    return !(root->left) && !(root->right); // 최 하단 노드인지 확인
}

void print_array(int codes[], int n){   // 배열 출력
    for(int i=0; i<n; i++){
        printf("%d", codes[i]);
    }
    printf("\n");
}

void print_codes(TreeNode *root, int codes[], int top){
    if(root->left){
        codes[top] = 1;
        print_codes(root->left, codes, top+1);
    }

    if(root->right){
        codes[top] = 0;
        print_codes(root->right, codes, top+1);
    }

    if(is_leaf(root)){
        printf("%c: ", root->ch);
        print_array(codes, top);    // 잎 노드일떄 출력
    }
}

void huffman_tree(int freq[], char ch_list[], int n){ // 허프만 코드
    TreeNode *node, *x;         // node와 x 포인터 선언
    HeapType* heap = create();  // heap을 동적 생성
    element e, e1, e2;
    int codes[100];
    int top = 0;

    init(heap);

    for(int i=0; i<n; i++){
        node = make_tree(NULL, NULL);
        e.ch = node->ch = ch_list[i];
        e.key = node->weight = freq[i];
        e.ptree = node;
        insert_min_heap(heap, e);
    }

    for(int i=1; i<n; i++){
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);

        x = make_tree(e1.ptree, e2.ptree);
        e.key = x->weight = e1.key + e2.key;
        e.ptree = x;
        printf("%d+%d->%d \n", e1.key, e2.key, e.key);
        insert_min_heap(heap, e);
    }

    e = delete_min_heap(heap);
    print_codes(e.ptree, codes, top);
    destory_tree(e.ptree);
    free(heap);
}

int main(void){
    char ch_list[] = {'s','i','n','t','e'};
    int freq[] = {6,4,8,12,15};             // 정렬이 안되어있어도 가능
    huffman_tree(freq, ch_list, 5);

    return 0;
}