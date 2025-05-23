#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

    string S, T;
    cin >> S >> T;
    
    while(T.length() > S.length()) {
        if(T.back() == 'A') T.erase(T.end()-1);
        else if(T.back() == 'B') {
            T.erase(T.end()-1);
            reverse(T.begin(), T.end());
        }
    }
    
    if(T == S) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}