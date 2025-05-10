#include <iostream>
using namespace std;

int main() {
    int N;
    __int128 sum;
    for(int i = 0; i < 3; i++) {
        cin >> N;
        sum = 0;
        long long number;
        while(N--) {
            cin >> number;
            sum += number;
        }
        if(sum == 0) cout << 0 << '\n';
        if(sum > 0) cout << "+" << '\n';
        if(sum < 0) cout << "-" << '\n';
    }
    
    return 0;
}