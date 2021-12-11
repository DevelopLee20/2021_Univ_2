#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define KEY_SIZE 7
#define SIZE 10

typedef struct{
    char key[KEY_SIZE];
    char number[14];
} element;

struct list{
    element item;
    struct list *link;
};

struct list *hash_table[TABLE_SIZE];

int transform(char *key){
    int number = 0;

    while(*key){
        number = number + *key++;
    }
    return number;
}

int hash_function(char *key){
    return transform(key) % TABLE_SIZE;
}

int hash_chain_add(element item, struct list *ht[]){
    int hash_value = hash_function(item.key);
    struct list *ptr;
    struct list *node_before = NULL, *node = ht[hash_value];
    for(; node; node_before = node, node=node->link){
        if(!strcmp(node->item.key,item.key)){
            fprintf(stderr, "이미 탐색키가 저장되어 있음\n");
            return EXIT_FAILURE;
        }
    }
    ptr = (struct list*)malloc(sizeof(struct list));
    ptr->item = item;
    ptr->link = NULL;

    if(node_before){
        node_before->link = ptr;
    }
    else{
        ht[hash_value] = ptr;
    }
}

void hash_chain_search(element item, struct list *ht[]){
    struct list *node;

    int hash_value = hash_function(item.key);
    for(node = ht[hash_value]; node; node=node->link){
        if(!strcmp(node->item.key,item.key)){
            printf("탐색 %5s 성공 %s\n", item.key, item.number);
            return;
        }
    }
    printf("키를 찾지 못했음\n");
}

void hash_chain_print(struct list *ht[]){
    struct list *node;
    int i;
    printf("===================\n");
    for(i=0; i<TABLE_SIZE; i++){
        printf("[%d]->",i);
        for(node=ht[i]; node; node=node->link){
            printf("%s->", node->item.key);
        }
        printf("\n");
    }
    printf("===================\n");
}

int main(void){
    char name[TABLE_SIZE][KEY_SIZE] = {
        "Hong","Kim","Lee","Nam","Cheon",
        "Ahn","Park","Shin","Oh","Gu"
    };

    char number[TABLE_SIZE][15] = {
        "010-1234-0001","010-1234-0002",
        "010-1234-0003","010-1234-0004",
        "010-1234-0005","010-1234-0006",
        "010-1234-0007","010-1234-0008",
        "010-1234-0009","010-1234-0010"
    };

    element e;

    for(int i=0; i<SIZE; i++){
        strcpy(e.key,name[i]);
        strcpy(e.number,number[i]);
        hash_chain_add(e, hash_table);
    }

    hash_chain_print(hash_table);

    for(int i=0; i<SIZE; i++){
        strcpy(e.key,name[i]);
        strcpy(e.number,number[i]);
        hash_chain_search(e, hash_table);
    }
    return 0;
}