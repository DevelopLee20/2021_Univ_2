#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX(a,b) (((a)>(b)) ? (a) : (b))

typedef struct AVLNode{
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

int get_height(AVLNode *node){
    int height = 0;
    if(node != NULL){
        height = 1 + MAX(get_height(node->left),get_height(node->right));
    }

    return height;
}

int get_balance(AVLNode *node){
    if(node == NULL) return 0;

    return get_height(node->left) - get_height(node->right);
}

AVLNode* create_node(int key){
    AVLNode *node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

AVLNode *rotate_right(AVLNode *parent){
    AVLNode *child = parent->left;
    parent->left = child->right;
    child->right = parent;

    return child;
}

AVLNode *rotate_left(AVLNode *parent){
    AVLNode *child = parent->right;
    parent->right = child->left;
    child->left = parent;

    return child;
}

AVLNode *insert(AVLNode *node, int key){
    if(node == NULL){
        return create_node(key);
    }
    if(key < node->key){
        node->left = insert(node->left, key);
    }
    else if(key > node->key){
        node->right = insert(node->right, key);
    }
    else{
        return node;
    }

    int balance = get_balance(node);

    if(balance > 1 && key < node->left->key){
        return rotate_right(node);
    }

    if(balance < -1 && key > node->right->key){
        return rotate_left(node);
    }

    if(balance > 1 && key > node->left->key){
        node->left = rotate_left(node->left);

        return rotate_right(node);
    }

    if(balance < -1 && key < node->right->key){
        node->right = rotate_right(node->right);

        return rotate_left(node);
    }
    return node;
}

void preorder(AVLNode *root){
    if(root != NULL){
        preorder(root->left);
        preorder(root->right);
    }
}

AVLNode* rand_Array(AVLNode *node, int n){
    int list[50000];    // 최대 배열 선언

    srand(time(NULL));  // 랜덤하게 배열 생성
    for(int i=0; i<n; i++){
        // 범위에 따른 키 값 생성
        int key = (rand()*rand()%n)+1;
        list[i] = key;  // 배열에 대입

        // 만약 key가 존재할 경우 판단
        for(int j=0; j<i; j++){
            if(key == list[j]){
                i--;    // 존재하면 배열 재생성
                break;
            }
        }
    }

    for(int i=0; i<n; i++){
        // 생성된 배열을 insert 함수 실행
        node = insert(node,list[i]);
    }
    return node;
}

int main(void){

    int count[5] = {100,500,1000,10000,50000};
 
    AVLNode *root = NULL;

    for(int i=0; i<5; i++){
        root = rand_Array(root, count[i]);  // 랜덤 배열 생성후 insert 실행
        printf("%d 전위 순회 결과\n", count[i]);  
        preorder(root);                     // 트리 출력
        printf("평균 높이: %d\n", get_height(root));    // 평균 높이 출력
        printf("2[log2(n+1)]: %d\n", (int)(log2((double)(count[i]+1))));
        printf("\n");
        root = NULL;    // 루트 초기화
    }

    return 0;
}