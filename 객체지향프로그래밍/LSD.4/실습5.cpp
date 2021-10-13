#include <iostream>
#include <string>
using namespace std;

int main(void){
    string prob = "space";
    int length = prob.length();
    int tries = 0;

    string answer(length, '-');

    cout << "현재 상태: " << answer << endl;

    while(tries < 6 && answer != prob){
        char c;
        cout << "글자를 추측하시오: ";
        cin >> c;

        if(answer.find(c) != string::npos){ // string::npos -> find 메소드에 의해서 찾았는데, 단어가 없는 경우 반환되는 값
            cout << "전과 동일한 글자입니다.";
            continue;
        }
        
        int pos = prob.find(c);
        if(pos == string::npos){
            cout << "추측한 글자가 없습니다." << endl;
            tries++;
            continue;
        }
        else{
            answer[pos] = c;
            pos = prob.find(c, pos+1);

            while(pos != string::npos){
                answer[pos] = c;
                pos = prob.find(c, pos+1);
            }
        }

        cout << "현재 상태: " << answer << endl;
        
        if(answer == prob){
            cout << "맞았습니다" << endl;
            break;
        }
    }

    if(tries >= 6){
        cout << "틀렸습니다. 정답은 " << prob << "입니다." << endl;
    }

    return 0;
}