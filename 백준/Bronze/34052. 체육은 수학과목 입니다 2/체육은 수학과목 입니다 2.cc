#include <iostream>
using namespace std;

int main() {
    int t, total = 0;
    for(int i = 0; i < 4; i++) {
        cin >> t;
        total += t;
    }
    
    if(total+300 <= 1800) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}