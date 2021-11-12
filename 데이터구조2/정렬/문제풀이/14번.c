////////////////////////////////////////////////////////

#include <stdio.h>

void print_step(int list[], int num, int key){
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

    if(key != -1){
        printf(" %d삽입",key);
    }
    printf("\n");
}

void insertion_sort(int list[], int n){
    int j, key, temp=list[0];
    print_step(list, 0, -1);

    for(int i=1; i<n; i++){
        key = list[i];
        print_step(list, i, temp);
        
        for(j=i-1; j>=0 && list[j]>key; j--){
            list[j+1] = list[j];
        }
        list[j+1] = key;
        temp = key;
    }
    print_step(list, 6, key);
}

int main(void){
    int list[6];

    for(int i=0; i<6; i++){
        scanf("%d",&list[i]);
    }

    insertion_sort(list, 6);

    return 0;
}

////////////////////////////////////////////////////////