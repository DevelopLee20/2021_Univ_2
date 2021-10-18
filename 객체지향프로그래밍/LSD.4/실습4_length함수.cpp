#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s;
    cout << "주민등록번호를 입력하시오: ";
    cin >> s;

    cout << "-가 제거된 주민등록번호: ";
    
    for(int i=0; i<s.length(); i++){    // length() string의 전체 길이 반환
        if (s[i] == '-'){               // 이거 찾았으면 출력안함 (제거한다구요)
            continue;
        }
        cout << s[i];                   // 출력
    }
    cout << endl;

    return 0;
}