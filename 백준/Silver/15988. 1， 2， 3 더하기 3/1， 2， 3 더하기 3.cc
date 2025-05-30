#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long n, T;
    cin >> T;
    while(T--) {
        cin >> n;
        long long dp[n+1] = {0, 1, 2, 4};
        for(int i = 4; i <= n; i++)
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
        cout << dp[n] << '\n';
    }
}