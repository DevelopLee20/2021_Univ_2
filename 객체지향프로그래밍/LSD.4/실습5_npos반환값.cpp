#include <iostream>
#include <string>
using namespace std;

// find(비교할 문자열, 시작할 위치);
// 핵맨 이었다

int main(void){
    string prob = "space";
    int length = prob.length();  // 문자열의 길이 5 반환
    int tries = 0;

    string answer(length, '-'); // string 문자열이름(길이, 특정 문자)

    cout << "현재 상태: " << answer << endl;

    // 시도가 5회 넘어가면 틀림
    while(tries < 6 && answer != prob){
        char c;                         // 문자 c 저장
        cout << "글자를 추측하시오: ";
        cin >> c;                       // 문자 c 초기화

        // 현재 나와있는거랑 문자 중복인지 확인
        if(answer.find(c) != string::npos){ // string::npos -> find 메소드에 의해서 찾았는데, 단어가 없는 경우 반환되는 값
            cout << "전과 동일한 글자입니다.";
            continue;
        }
        
        // 위에 나와있지 않은데 시도했지만 틀렸을때
        int pos = prob.find(c);
        if(pos == string::npos){
            cout << "추측한 글자가 없습니다." << endl;
            tries++;
            continue;
        }
        // 시도했는데 맞았을때
        else{
            answer[pos] = c; // 특정 위치의 문자를 나타내줌
            pos = prob.find(c, pos+1); // 뒤에 문자가 더 있는지 확인

            while(pos != string::npos){ // 뒤에 문자가 더이상 없으면 종료
                answer[pos] = c;
                pos = prob.find(c, pos+1);
            }
        }

        cout << "현재 상태: " << answer << endl;
        
        // 정답일때 반복종료
        if(answer == prob){
            cout << "맞았습니다" << endl;
            break;
        }
    }

    // 시도횟수 6회 이상이면 틀림
    if(tries >= 6){
        cout << "틀렸습니다. 정답은 " << prob << "입니다." << endl;
    }

    return 0;
}