#include <iostream>
#include <string>   // string 사용가능함
using namespace std;

int main(void){
    string s1 = "This is a test.";

    s1.insert(4, "Hello");          // 4에 끼어넣기 함
    cout << s1 << endl;             // 출력   
    int index = s1.find("test");    // test를 찾아서 인덱스를 반환함 처음 정수가 반환됨
    cout << index << endl;          // 출력
    s1.append("World");             // 맨 뒤에 문장 추가
    cout << s1 << endl;             // 출력

    return 0;
}