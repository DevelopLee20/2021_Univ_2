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
    printf("key: %d\n", key);
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
        printf("LL %d\n", key);
        return rotate_right(node);
    }

    if(balance < -1 && key > node->right->key){
        printf("RR %d\n", key);
        return rotate_left(node);
    }

    if(balance > 1 && key > node->left->key){
        printf("LR %d\n", key);
        node->left = rotate_left(node->left);

        return rotate_right(node);
    }

    if(balance < -1 && key < node->right->key){
        printf("RL %d\n", key);
        node->right = rotate_right(node->right);

        return rotate_left(node);
    }
    return node;
}

void preorder(AVLNode *root){
    if(root != NULL){
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(void){

    int count[12] = {12,1,4,3,7,8,10,2,9,11,6,5};

    AVLNode *root = NULL;

    for(int i=0; i<12; i++){
        root = insert(root, count[i]);
    }

    preorder(root);

    return 0;
}