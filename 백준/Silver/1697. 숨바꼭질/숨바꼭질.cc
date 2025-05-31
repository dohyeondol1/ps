#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001] = { 1000000001, };

int main() {
	int N, K;
	cin >> N >> K;
	dp[N] = 0;

	for(int i=N-1; i >= 0; i--)
		dp[i] = N - i;

	for(int i = N+1; i <= K; i++) {
		if(i%2 == 0) dp[i] = min(dp[i-1]+1, dp[i/2]+1);
		else dp[i] = min(dp[i-1]+1, dp[(i+1)/2]+2);
	}

 	cout << dp[K] << endl;
	return 0;
}