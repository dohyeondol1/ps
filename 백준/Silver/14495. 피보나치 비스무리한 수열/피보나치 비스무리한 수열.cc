#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    long long dp[117];
    dp[0] = dp[1] = dp[2] = 1;
    for(int i = 3; i < N; i++)
        dp[i] = dp[i-1] + dp[i-3];
    
    cout << dp[N-1] << '\n';
    return 0;
}