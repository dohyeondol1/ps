#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
    int n;
	cin >> n;
	vector<long long> dp(n+1);		
	dp[1] = dp[2] = 1;
	for(int i = 3; i <= n; i++)
		dp[i] = (dp[i-1]+dp[i-2]);
	
    cout << dp[n] << '\n';
	
	return 0;
}