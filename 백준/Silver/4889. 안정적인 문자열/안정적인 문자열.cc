#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int testCase = 1;
    while(true) {
        string s;
        cin >> s;
        if(s[0] == '-') break;
        
        int answer = 0;
        int open = 0;
        for(char c : s) {
            if(c == '{')
                open++;
            else {
                if(open == 0) {
                    answer++;
                    open++;
                } 
                else
                    open--;
            }
        }
        answer += open / 2;
        cout << testCase << ". " << answer << '\n';
        testCase++;
    }
    
    return 0;
}