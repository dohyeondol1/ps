#include <iostream>
#include <vector>
using namespace std;

long long dp[8], temp[8];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
	int D;
	cin >> D;

    dp[0] = 1;
    while(D--) {
        temp[0] = dp[1] + dp[2];
        temp[1] = dp[0] + dp[2] + dp[3];
        temp[2] = dp[0] + dp[1] + dp[3] + dp[4];
        temp[3] = dp[1] + dp[2] + dp[4] + dp[5];
        temp[4] = dp[2] + dp[3] + dp[5] + dp[6];
        temp[5] = dp[3] + dp[4] + dp[7];
        temp[6] = dp[4] + dp[7];
        temp[7] = dp[5] + dp[6];

        for(int i = 0; i < 8; i++)
            dp[i] = temp[i] % 1000000007;
    }
    
    cout << dp[0] << '\n';
	return 0;
}