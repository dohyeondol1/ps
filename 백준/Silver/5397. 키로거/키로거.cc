#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int TestCaseCount;
    cin >> TestCaseCount;

    while(TestCaseCount--) {
        string password;
        cin >> password;
        
        list<char> result;
        auto cursor = result.begin();
        
        for(char pw : password) {
            if(pw == '<') {
                if(cursor != result.begin()) cursor--;
            }
            else if(pw == '>') {
                if(cursor != result.end()) cursor++;
            }
            else if(pw == '-') {
                if(cursor != result.begin()) {
                    cursor--;
                    cursor = result.erase(cursor);
                }
            }
            else result.insert(cursor, pw);
        }
        
        for(char pw : result)
            cout << pw;
        
        cout << '\n';
    }

    return 0;
}