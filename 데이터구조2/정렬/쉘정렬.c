#include <stdio.h>

inc_insertion_sort(int list[], int first, int last, int gap){
    int key;

    for(int i=first+gap; i<=last; i=i+gap){
        key = list[i];

        for(int j=i-gap; j>=first && key<list[j]; j=j-gap){0
            list[j+gap] = list[j];
        }
        list[j+gap] = key;
    }
}

void shell_sort(int list[], int n){
    for(int gap=n/2; gap>0; gap=gap/2){

    }

}