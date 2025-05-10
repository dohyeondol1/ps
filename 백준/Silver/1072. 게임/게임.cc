#include <iostream>
using namespace std;

int main() {
    long long X, Y, Z, minCount;
    cin >> X >> Y;
    Z = 100*Y/X;
    
    if(Z >= 99) {
        cout << -1 << '\n';
        return 0;
    }
    
    long long left = 0, right = 1000000000;
    while(left <= right) {
        long long mid = (left+right)/2;
        long long newWinRate = 100*(Y+mid)/(X+mid);
        
        if(newWinRate > Z) {
            minCount = mid;
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }
    
    cout << minCount << '\n';
    
    return 0;
}