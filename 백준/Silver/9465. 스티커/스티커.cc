#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<vector<int>> sticker(2, vector<int> (n+1));
        vector<vector<int>> dp(2, vector<int> (n+1));
        for(int i = 0; i < 2; i++)
            for(int j = 1; j <= n; j++)
                cin >> sticker[i][j];
        
        dp[0][0] = dp[1][0] = 0;
        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];

        for(int i = 2; i <= n; i++){
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + sticker[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + sticker[1][i];
        }

        cout << max(dp[0][n], dp[1][n]) << '\n';
    }
    
	return 0;
}