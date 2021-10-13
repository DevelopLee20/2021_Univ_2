#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
    int key;
    ListNode *link;
    int heap_size;
} ListNode;

ListNode* void create(){
    return (ListNode *)malloc(sizeof(ListNode));
}

void init(ListNode *list){
    list = NULL;
}

int is_empty(ListNode* list){
    if (list->heap_size == 0)
        return 1;
    else
        return 0;
}

int is_full(ListNode* h){
    if (h->heap_size == 200)
        return 1;
    else
        return 0;
}

ListNode* insert(ListNode* list, int item){
    ListNode* node = list;
    ListNode* new;

    while(node != NULL || node->key < item)
        node = node->link;
    new->key = item;
    new->link = node;

    return new
}

ListNode* find(ListNode* list){
    return list->key;
}

ListNode* delete(ListNode* list){
    return list->link
}

int main(void){

    ListNode *list = NULL; // init()

    list = insert_first(list, 10);
    list = insert_first(list, 20);
    list = insert_first(list, 30);

    printf("1) ");
    print_list(list);

    list = delete_first(list);
    list = insert_first(list, 40);
    list = insert_first(list, 50);
    list = delete_first(list);

    printf("2) ");
    print_list(list);

    return 0;
}