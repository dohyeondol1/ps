#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    vector<int> coin(n);
    for(auto &c : coin)
        cin >> c;
    
    vector<int> dp(k+1, 1e9);
    for(int i = 0; i < n; i++)
        dp[coin[i]] = 1;

    for(int i = 0; i < n; i++)
        for(int j = coin[i]; j <= k; j++)
            dp[j] = min(dp[j], dp[j-coin[i]]+1);

    if(dp[k] == 1e9) cout << -1 << '\n';
    else cout << dp[k] << '\n';
    
    return 0;
}