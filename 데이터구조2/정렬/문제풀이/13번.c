////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

#define NAME_SIZE 3

typedef struct{
    int key;
    char name[NAME_SIZE];
} record;

void insertion_sort(record *r){
    int j, key;
    char temp[NAME_SIZE];

    for(int i=1; i<6; i++){
        key = r[i].key;
        strcpy(temp,r[i].name);
        for(j=i-1; j>=0 && r[j].key>key; j--){
            r[j+1].key = r[j].key;
            strcpy(r[j+1].name,r[j].name);
        }
        r[j+1].key = key;
        strcpy(r[j+1].name,temp);
    }
}

int main(void){
    record recode[6] = {{26,"JJ"},{21,"IG"},{25,"HR"},{22,"SH"},{22,"SM"},{23,"DH"}};

    for(int i=0; i<6; i++){
        printf(" %d %s |",recode[i].key, recode[i].name);
    }

    printf("\n");

    insertion_sort(recode);

    for(int i=0; i<6; i++){
        printf(" %d %s |",recode[i].key, recode[i].name);
    }
    
    return 0;
}

////////////////////////////////////////////////////////