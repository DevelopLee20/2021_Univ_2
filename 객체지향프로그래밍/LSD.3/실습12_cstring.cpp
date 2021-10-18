#include <iostream>
#include <cstring>  // strcpy, strcat, strcmp
using namespace std;

int main(void){
    char string[80];

    strcpy(string, "Hello  World from ");   // strcpy(변수, 내용);
    strcat(string, "strcpy() ");            // strcat(변수, 내용);
    strcat(string, "and ");                 // strcat(변수, 내용);
    strcat(string, "strcat()!");            // strcat(변수, 내용);
    cout << string << endl;

    return 0;
}