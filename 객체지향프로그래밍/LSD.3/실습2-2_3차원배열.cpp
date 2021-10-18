#include <iostream>
using namespace std;

int main(void){
    int s[3][3][3]; // 3차원 배열 s 선언
    int i = 1;

    for(int z=0; z<3; z++){         // z 3회만 큼 반복
        for(int y=0; y<3; y++){     
            for(int x=0; x<3; x++){
                s[z][y][x] = i++;   // 3중 배열에 그냥 i 저장함
            }
        }
    }
    return 0;
}