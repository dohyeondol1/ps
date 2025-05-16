#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()  {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n;
	cin >> n;
	
	vector<vector<int>> triangle(n, vector<int> (n));
	for(int i = 0; i < n; i++)
	    for(int j = 0; j <= i; j++)
	        cin >> triangle[i][j];
	
	vector<vector<int>> dp(n, vector<int> (n, 0));
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i-1][j-1] + triangle[i][j], dp[i-1][j] + triangle[i][j]);
        }
    }
    
    sort(dp[n-1].begin(), dp[n-1].end());
    
    cout << dp[n-1][n-1] << '\n';

	return 0;
}