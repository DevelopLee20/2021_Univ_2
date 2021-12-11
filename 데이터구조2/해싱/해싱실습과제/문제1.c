#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 7
#define TABLE_SIZE 10
#define HASH_KEY 7
#define empty(item) (strlen(item.key) == 0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))

typedef struct{
    char key[KEY_SIZE];
    char number[14];
} element;

element hash_table[TABLE_SIZE];

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

int hash_function2(char *key){
    return (HASH_KEY - (transform(key) % HASH_KEY));
}

void hash_dh_add(element item, element ht[]){
    int i, hash_value, inc;
    hash_value = i = hash_function(item.key);
    inc = hash_function2(item.key);

    while(!empty(ht[i])){
        if(equal(item, ht[i])){
            fprintf(stderr, "탐색키가 중복되었습니다.\n");
            exit(1);
        }
        i = (i + inc) % TABLE_SIZE;

        if(i == hash_value){
            fprintf(stderr, "테이블이 가득찼습니다.\n");
            exit(1);
        }
    }
    ht[i] = item;
}

void hash_dh_search(element item, element ht[]){
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while(!empty(ht[i])){
        if(equal(item, ht[i])){
            printf("탐색 %5s 성공 %s\n", item.key, item.number);
            return;
        }
        i = (i+1) % TABLE_SIZE;
        if(i == hash_value){
            printf("찾는 값이 테이블에 없음\n");
            return;
        }
    }
    printf("찾는 값이 테이블에 없음\n");
    return;
}

void table_print(element ht[]){
    printf("==============\n");
    for(int i=0; i<TABLE_SIZE; i++){
        printf("[%d] %s\n", i, ht[i].key);
    }
    printf("==============\n");
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

    for(int i=0; i<TABLE_SIZE; i++){
        strcpy(e.key,name[i]);
        strcpy(e.number,number[i]);
        hash_dh_add(e, hash_table);
    }

    table_print(hash_table);

    for(int i=0; i<TABLE_SIZE; i++){
        strcpy(e.key,name[i]);
        strcpy(e.number,number[i]);
        hash_dh_search(e, hash_table);
    }

    return 0;
}