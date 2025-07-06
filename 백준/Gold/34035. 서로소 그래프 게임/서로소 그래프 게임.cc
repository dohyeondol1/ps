#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        if(N == 2)
            cout << "kang" << '\n';
        else
            cout << "chan" << '\n';
    }
    
    return 0;
}