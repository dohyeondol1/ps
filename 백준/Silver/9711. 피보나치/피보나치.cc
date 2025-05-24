#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        vector<long long> dp(10001);
        dp[1] = dp[2] = 1;
        
        long long P, Q;
        cin >> P >> Q;
        for(int i = 3; i <= P; i++)
            dp[i] = (dp[i-1] + dp[i-2])%Q;
        if(Q == 1) dp[P] = 0;
        cout << "Case #" << t << ": " << dp[P] << '\n'; 
    }
    
    return 0;
}