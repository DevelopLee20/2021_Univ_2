#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void print_step(int list[], int num, int one, int two){
    printf("(");
    for(int i=0; i<num; i++){
        if(i == num-1){
            printf("%d",list[i]);
            break;
        }
        printf("%d,",list[i]);
    }
    printf(") ");

    printf(" (");
    for(int i=num; i<6; i++){
        if(i == 6-1){
            printf("%d",list[i]);
            break;
        }
        printf("%d,",list[i]);
    }
    printf(") ");

    if(one == -1){
        printf(" 초기상태");
    }
    else{
        printf("%d선택 후 %d과 교환", one, two);
    }
    printf("\n");
}

void selection_sort(int list[], int n){
    int least, temp;
    int before1=-1, before2=-1;

    for(int i=0; i<n; i++){
        least = i;
        for(int j=i+1; j<n; j++){
            if(list[j] < list[least]){
                least = j;
            }
        }
        print_step(list, i, before1, before2);
        SWAP(list[i], list[least], temp);
        before1 = list[i];
        before2 = list[least];
    }
    print_step(list, 6, before1, before2);
}

int main(void){
    int list[6] = {17,9,21,6,3,12};

    selection_sort(list, 6);

    return 0;
}