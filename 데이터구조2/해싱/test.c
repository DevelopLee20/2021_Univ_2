#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    char *ma = malloc(sizeof(char)*3);
    char name[3];
    name[0] = 65;
    name[1] = 76;
    name[2] = '\0';

    ma = name;
    printf("%s",ma);

    return 0;
}