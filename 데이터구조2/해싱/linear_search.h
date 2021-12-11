#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    return transform(key) % TABLE_SIZE; // 교재 오타
}

int hash_lp_add(element item, element ht[]){
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while(!empty(ht[i])){
        if(equal(item, ht[i])){
            fprintf(stderr, "탐색키가 중복되었습니다.\n");
            exit(1);
        }
        i = (i+1) % TABLE_SIZE;
        if(i == hash_value){
            fprintf(stderr, "테이블이 가득찼습니다.\n");
            exit(1);
        }
    }
    ht[i] = item;
    return i;
}

void hash_lp_search(element item, element ht[]){
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while(!empty(ht[i])){
        if(equal(item, ht[i])){
            printf("%s은 해쉬 테이블 %d 인덱스에 있음!\n", item.key, i);
        }
        i = (i+1) % TABLE_SIZE;
        if(i == hash_value){
            printf("찾는 값이 테이블에 없음\n");
        }
    }
    printf("찾는 값이 테이블에 없음\n");
}

void hash_lp_print(element ht[]){
    printf("\n======================\n");
    for(int i=0; i<TABLE_SIZE; i++){
        printf("[%d] %s\n", i, ht[i].key);
    }
    printf("\n======================\n");
}

int main(void){
    char *s[7] = {"do","for","if","case","else","return","function"};
    element e;

    for(int i=0; i<7; i++){
        strcpy(e.key, s[i]);
        hash_lp_add(e,hash_table);
        hash_lp_print(hash_table);
    }
    for(int i=0; i<7; i++){
        strcpy(e.key, s[i]);
        hash_lp_search(e, hash_table);
    }
    return 0;
}