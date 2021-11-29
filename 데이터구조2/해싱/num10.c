#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 4
#define TABLE_SIZE 1000
#define empty(item) (strlen(item.key) == 0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))

// #define DEBUG

typedef struct{
    char key[KEY_SIZE];
} element;

int lp_move = 0;
int dh_move = 0;

element hash_table1[TABLE_SIZE];
element hash_table2[TABLE_SIZE];

int transform(char *key){
    int number = 0;

    while(*key){
        // number = 31 * number + *key++;
        // 결과를 보기 위해선 아래 코드 사용이 맞음
        number = number + *key++;
    }
    return number;
}

int hash_function(char *key){
    return transform(key) % TABLE_SIZE;
}

// 이중해싱법
void hash_dh_add(element item, element ht[]){
    int i, hash_value, inc;
    hash_value = i = hash_function(item.key);
    inc = hash_function(item.key);

    while(!empty(ht[i])){
        if(equal(item, ht[i])){
            fprintf(stderr, "탐색키가 중복되었습니다.\n");
            exit(1);
        }
        i = (i + inc) % TABLE_SIZE;
        dh_move += 1;
        if(i == hash_value){
            fprintf(stderr, "테이블이 가득찼습니다.\n");
            exit(1);
        }
    }
    ht[i] = item;
}

// 선형조사법
void hash_lp_add(element item, element ht[]){
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while(!empty(ht[i])){
        if(equal(item, ht[i])){
            fprintf(stderr, "탐색키가 중복되었습니다.\n");
            exit(1);
        }
        i = (i+1) % TABLE_SIZE;
        lp_move += 1;
        if(i == hash_value){
            fprintf(stderr, "테이블이 가득찼습니다.\n");
            exit(1);
        }
    }
    ht[i] = item;
}

void init_dh(){
    char *cast = malloc(sizeof(char)*3);
    char name[KEY_SIZE];
    element e;

    for(int i=0; i<500; i++){
        name[0] = 65 + (i % 26);
        name[1] = 65 + ((i / 26) % 26);
        name[2] = 0;

        cast = name;
        strcpy(e.key,cast);
        hash_lp_add(e, hash_table1);
    }
}

void init_lp(){
    char *cast = malloc(sizeof(char)*3);
    char name[KEY_SIZE];
    element e;

    for(int i=0; i<500; i++){
        name[0] = 65 + (i % 26);
        name[1] = 65 + ((i / 26) % 26);
        name[2] = 65 + ((i / (26*26)) % 26);
        name[3] = 0;

        cast = name;
        strcpy(e.key,cast);
        hash_lp_add(e, hash_table2);
    }
}

int main(void){
    init_lp();
    init_dh();

    printf("lp: %d\n", lp_move);
    printf("dh: %d\n", dh_move);
    return 0;
}