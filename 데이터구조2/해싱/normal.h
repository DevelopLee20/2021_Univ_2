#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 10
#define TABLE_SIZE 13
#define empty(item) (strlen(item.key) == 0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))

typedef struct{
    char key[KEY_SIZE];
} element;

element hash_table[TABLE_SIZE];

void init_table(element ht[]){
    for(int i=0; i<TABLE_SIZE; i++){
        ht[i].key[0] = NULL;
    }
}