#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 4
#define TABLE_SIZE 1000
#define empty(item) (strlen(item.key) == 0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))

typedef struct{
    char key[KEY_SIZE];
} element;

int lp_move = 0;
int dh_move = 0;

int rand_array[TABLE_SIZE];
char cast[TABLE_SIZE][KEY_SIZE];

element hash_table1[TABLE_SIZE];
element hash_table2[TABLE_SIZE];

int hash_function(char *key){
    int hash_index = 0;
    while(*key){
        hash_index = 31 * hash_index + *key++;
    }
    return hash_index;
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
    element e;

    for(int i=0; i<500; i++){
        strcpy(e.key,cast[i]);
        hash_dh_add(e, hash_table1);
    }
}

void init_lp(){
    element e;

    for(int i=0; i<500; i++){
        strcpy(e.key,cast[i]);
        hash_lp_add(e, hash_table2);
    }
}

void make_rand(){
    for(int i=0; i<TABLE_SIZE; i++){
            rand_array[i] = i;
    }

    srand(time(NULL));
    for(int i=0; i<TABLE_SIZE; i++){
        int cast_a = rand() % 500;
        int cast_b = rand() % 500;
        int temp = rand_array[cast_a];
        rand_array[cast_a] = rand_array[cast_b];
        rand_array[cast_b] = temp;
    }

    char name[KEY_SIZE];

    for(int i=0; i<500; i++){
        name[0] = 65 + (i % 26);
        name[1] = 65 + ((i / 26) % 26);
        name[2] = 0;

        strcpy(cast[rand_array[i]],name);
    }
}

int main(void){
    make_rand();
    init_lp();
    init_dh();

    printf("TABLE SIZE: [%d]\n", TABLE_SIZE);
    printf("lp 충돌: %d\n", lp_move);
    printf("dh 충돌: %d\n", dh_move);
    return 0;
}