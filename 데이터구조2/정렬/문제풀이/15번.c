#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *link;
} ListNode;

ListNode* get_node(int item){
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = item;
    node->link = NULL;

    return node;
}

ListNode* insert_first(ListNode *list, int val){
    ListNode *node = get_node(val);
    node->link = list;

    return node;
}

void insertion_sort(ListNode *head, int n){
    int i, j;
    ListNode *node = head;
    ListNode *temp;

    for(int i=1; i<n-1; i++){
        temp = node->link;
        
        for(j=i-1; j>=0 && node->data; j--){
            node->link = node;
        }
        node->link = temp;
    }
}

void print_list(ListNode *list){

    printf("|");

    ListNode *p = list;

    while(p != NULL){ // NULL을 만날때까지 반복
        printf(" %d |", p->data);
        p = p->link;
    }
    
    printf("\n");
}

int main(void){
    int list[8] = {5,7,4,9,8,5,6,3};

    ListNode *head;

    for(int i=7; i>-1; i--){
        head = insert_first(head, list[i]);
    }
    print_list(head);

    return 0;
}