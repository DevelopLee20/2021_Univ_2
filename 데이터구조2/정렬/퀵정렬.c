#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int partition(int list[], int left, int right){
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do{
        do{
            low++;
        } while(list[low]<pivot);
        do{
            high--;
        } while(list[high]>pivot);
        if(low<high){
            SWAP(list[low],list[high],temp);
        }
    } while(low<high);

    SWAP(list[left],list[high],temp);

    return high;
}

void quick_sort(int list[], int left, int right){
    if(left<right){
        int q = partition(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
}

int main(void){
    int list[8] = {67,90,57,25,84,32,73,54};

    quick_sort(list, 0, MAX_SIZE-1);

    return 0;
}