#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> p(N+1);
    vector<int> dp(N+1, 0);
    for(int i = 1; i <= N; i++) {
        cin >> p[i];
        dp[i] = p[i];
    }
    
    for(int i = 1; i <= N; i++) {
        int count = 0;
        for(int j = 1; j <= i; j++) {
            int temp = i/j;
            if(j*temp != i) dp[i] = max(dp[i-j*temp]+dp[j]*temp, dp[i]);
            else dp[i] = max(dp[j]*temp, dp[i]);
        }
    }
    
    cout << dp[N] << '\n';

    return 0;
}