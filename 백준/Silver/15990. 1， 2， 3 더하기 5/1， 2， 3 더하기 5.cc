#include <iostream>
using namespace std;

#define MOD 1000000009
int dp[100001][4];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    dp[1][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for(int i = 4; i <= 100000; i++) {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
    }

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        cout << ((long long)dp[n][1] + dp[n][2] + dp[n][3]) % MOD << '\n';
    }

    return 0;
}