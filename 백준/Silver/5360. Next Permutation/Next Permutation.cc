#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    string A;
    int T;
    cin >> T;
    while(T--) {
        cin >> A;
        
        bool able =  next_permutation(A.begin(), A.end());
        if(able) cout << A << '\n';
        else cout << "USELESS" <<'\n';
    }
    
    return 0;
}