#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 7
#define SIZE 5

typedef struct{
    int key;
} element;

typedef struct ListNodePtr{
    element item;
    struct ListNodePtr *link;
} ListNodePtr;

ListNodePtr *hash_table[TABLE_SIZE];

int hash_function(int key){
    return key % TABLE_SIZE;
}

int hash_chain_add(element item, ListNodePtr *ht[]){
    int hash_value = hash_function(item.key);
    ListNodePtr *ptr;
    ListNodePtr *node_before = NULL, *node = ht[hash_value];
    for(; node; node_before = node, node=node->link){
        if(node->item.key == item.key){
            fprintf(stderr, "이미 탐색키가 저장되어 있음\n");
            return EXIT_FAILURE;
        }
    }
    ptr = (ListNodePtr*)malloc(sizeof(ListNodePtr));
    ptr->item = item;
    ptr->link = NULL;

    if(node_before){
        node_before->link = ptr;
    }
    else{
        ht[hash_value] = ptr;
    }
}

void hash_chain_search(element item, ListNodePtr *ht[]){
    ListNodePtr *node;

    int hash_value = hash_function(item.key);
    for(node = ht[hash_value]; node; node=node->link){
        if(node->item.key == item.key){
            fprintf(stderr, "탐색 %d 성공\n", item.key);
            return;
        }
    }
    printf("키를 찾지 못했음\n");
}

void hash_chain_print(ListNodePtr *ht[]){
    ListNodePtr *node;
    int i;
    printf("\n======================\n");
    for(i=0; i<TABLE_SIZE; i++){
        printf("[%d]->",i);
        for(node=ht[i]; node; node=node->link){
            printf("%d->", node->item.key);
        }
        printf("\n");
    }
    printf("==================\n");
}

void hash_chain_delete(element item, ListNodePtr *ht[]){
    ListNodePtr *node;

    int hash_value = hash_function(item.key);
    ListNodePtr *before = ht[hash_value];

    if(before->item.key == item.key){
        ht[hash_value] = before->link;
        printf("삭제 %d 성공\n", item.key);
        return;
    }

    for(node = ht[hash_value]; node; node=node->link){
        if(node->item.key == item.key){
            before->link = node->link;
            printf("삭제 %d 성공\n", item.key);
            return;
        }
        before = node;
    }
    printf("키를 찾지 못했음\n");
}

int main(void){
    int data[SIZE] = {8,1,9,6,13};
    element e;

    for(int i=0; i<SIZE; i++){
        e.key = data[i];
        hash_chain_add(e, hash_table);
        hash_chain_print(hash_table);
        printf("%d 삽입 성공\n", e.key);
    }

    e.key = data[0];
    hash_chain_delete(e, hash_table);
    hash_chain_print(hash_table);

    for(int i=1; i<SIZE; i++){
        e.key = data[i];
        hash_chain_search(e, hash_table);
    }
    return 0;
}