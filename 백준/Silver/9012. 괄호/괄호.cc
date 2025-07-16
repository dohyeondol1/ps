#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int T;
    char str[51];
    
    cin >> T;
    while(T--) {
        int count = 0;
        cin >> str;

        for(int j = 0; str[j]; j++) {
            count += (str[j] == '(') ? 1 : -1;
            if(count < 0) break; 
        }

        cout << (count == 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}