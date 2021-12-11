#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 10
#define TABLE_SIZE 20
#define empty(item) (strlen(item.key) == 0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))

typedef struct{
    char key[KEY_SIZE];
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

int hash_lp_add(element item){
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while(!empty(hash_table[i])){
        if(equal(item, hash_table[i])){
            fprintf(stderr, "탐색키가 중복되었습니다.\n");
            exit(1);
        }
        i = (i+1) % TABLE_SIZE;
        if(i == hash_value){
            fprintf(stderr, "테이블이 가득찼습니다.\n");
            exit(1);
        }
    }
    hash_table[i] = item;
    return i;
}

int hash_lp_search(element item){
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while(!empty(hash_table[i])){
        if(equal(item, hash_table[i])){
            printf("%s은 해쉬 테이블 %d 인덱스에 있음!\n", item.key, i);
            return EXIT_SUCCESS;
        }
        else if((i+1) % TABLE_SIZE == hash_value){
            printf("찾는 값이 테이블에 없음\n");
            return EXIT_SUCCESS;
        }
    }
    printf("찾는 값이 테이블에 없음\n");
    return EXIT_SUCCESS;
}

// 8번도 이 코드와 동일하다.
int hash_lp_delete(element item){
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while(!empty(hash_table[i])){
        if(equal(item, hash_table[i])){
            hash_table[i].key[0] = '\0';
            printf("%s를 해쉬 테이블 %d 인덱스에서 지웠음!\n", item.key, i);
            return EXIT_SUCCESS;
        }
        else if((i+1) % TABLE_SIZE == hash_value){
            printf("찾는 값이 테이블에 없음\n");
            return EXIT_SUCCESS;
        }
    }
    printf("찾는 값이 테이블에 없음\n");
    return EXIT_SUCCESS;
}

void call_insert(char name[]){
    element e;
    strcpy(e.key,name);
    int site = hash_lp_add(e);
    printf("인덱스 %d번에 저장되었음\n",site);
}

void call_search(char name[]){
    element e;
    strcpy(e.key,name);
    hash_lp_search(e);
}

void call_delete(char name[]){
    element e;
    strcpy(e.key,name);
    hash_lp_delete(e);
}

void interface(){
    char value;
    char name[10];

    printf("삽입(i), 탐색(s), 삭제(d): ");
    scanf("%c", &value);
    fflush(stdin);
    printf("동물의 이름: ");
    scanf("%s", &name);
    fflush(stdin);

    if(value == 'i'){
        call_insert(name);
    }
    else if(value == 's'){
        call_search(name);
    }
    else if(value == 'd'){
        call_delete(name);
    }
}

int main(void){
    while(1){
        printf("\n");
        interface();
    }
}