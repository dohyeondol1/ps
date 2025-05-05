#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, T;
    int dp[12];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < 11; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    
    cin >> T;
    while(T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}