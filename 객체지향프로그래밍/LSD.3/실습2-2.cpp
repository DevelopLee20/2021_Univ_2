#include <iostream>
using namespace std;

int main(void){
    int s[3][3][3];
    int i = 1;

    for(int z=0; z<3; z++){
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                s[z][y][x] = i++;
            }
        }
    }

    return 0;
}