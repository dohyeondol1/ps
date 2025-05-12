#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<int> dp(N+1);
    dp[1] = dp[3] = 0;
    dp[2] = dp[4] = 1;
    
    for(int i = 5; i <= N; i++) {
        if(dp[i-1] == 0 || dp[i-3] == 0 || dp[i-4] == 0) dp[i] = 1;
        else dp[i] = 0;
    }

    if(dp[N]) cout << "SK" << '\n';
    else cout << "CY" << '\n';
    
    return 0;
}