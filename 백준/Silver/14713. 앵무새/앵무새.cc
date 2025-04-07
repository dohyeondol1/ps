#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N, wordCount = 0;
    cin >> N;
    //입력 후 남은 버퍼의 개행문자를 무시하기
    cin.ignore();
    queue<string> S[N];
    string str, word;
    
    for(int i = 0; i < N; i++) {
        getline(cin, str);
        //공백 기준으로 문자열 파싱
        stringstream stream(str);
        //입력 스트림에서 값을 읽어오는 연산자 '>>'
        while(stream >> word) {
            S[i].push(word);
            wordCount++;
        }
    }
    
    getline(cin, str);
    stringstream stream(str);
    queue<string> L;
    while(stream >> word)
        L.push(word);
    
    if(L.size() != wordCount) {
        cout << "Impossible" << '\n';
        return 0;
    }
    
    int size = L.size();
    for(int i = 0; i < size; i++) {
        bool valid = false;
        for(int j = 0; j < N; j++) {
            if(!S[j].empty()) {
                if(L.front() == S[j].front()) {
                    L.pop();
                    S[j].pop();
                    valid = true;
                    break;
                }
            }
        }
        if(!valid) {
            cout << "Impossible" << '\n';
            return 0;
        }
    }

    cout << "Possible" << '\n';
    return 0;
}