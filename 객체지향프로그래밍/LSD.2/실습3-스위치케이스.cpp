#include <iostream>
using namespace std;

int main(void){
    int vowel = 0, consonant = 0;
    char ch;

    cout << "영문자를 입력하고 컨트롤-Z를 치세요" << endl;

    while(cin >> ch){
        switch (ch)
        {
        case 'a':
        case 'i':
        case 'e':
        case 'o':
        case 'u':   // 5개 중 하나를 받으면 문장 수행
            vowel++;
            break;
        
        default:    // 모두 아니라면 이 문장을 기본적으로 실행
            consonant++;
            break;
        }
    }

    cout << "모음: " << vowel << endl;      // 모음과 자음의 개수를 출력함
    cout << "자음: " << consonant << endl;  // 모음과 자음의 개수를 출력함

    return 0;
}