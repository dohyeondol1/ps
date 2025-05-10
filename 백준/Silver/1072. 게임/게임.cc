#include <iostream>
using namespace std;

long long binary_search(long long gameCount, long long winCount) {
    long long currentRate = 100*winCount/gameCount;
    long long result = -1;
    
    long long left = 0, right = 1e9;
    while(left <= right) {
        long long mid = (left+right)/2;
        long long newWinRate = 100*(winCount+mid)/(gameCount+mid);
        
        if(newWinRate > currentRate) {
            result = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    
    return result;
}

int main() {
    long long X, Y, Z;
    cin >> X >> Y;
    Z = 100*Y/X;
    
    if(Z >= 99) {
        cout << -1 << '\n';
        return 0;
    }
    
    long long minCount = binary_search(X, Y);
    cout << minCount << '\n';
    
    return 0;
}