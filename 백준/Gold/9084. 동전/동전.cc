#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n;
	    vector<int> coin(n);
	    for(auto& c : coin)
		    cin >> c;
        cin >> k;
        vector<int> dp(k+1);
	    
        dp[0] = 1;
	    for(int i = 0; i < n; i++)
		    for(int j = coin[i]; j <= k; j++) 
			    dp[j] += dp[j - coin[i]];

	    cout<< dp[k] << '\n';
    }

	return 0;
}