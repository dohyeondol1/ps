#include <iostream>
#include <vector>
using namespace std;

int dp[101][10];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;

    for(int i = 1; i <= 9; i++) 
        dp[1][i] = 1;

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j > 0) dp[i][j] += dp[i-1][j-1];
            if(j < 9) dp[i][j] += dp[i-1][j+1];
            dp[i][j] %= 1000000000;
        }
    }

    int answer = 0;
    for(int i = 0; i <= 9; i++)
        answer = (answer + dp[N][i]) % 1000000000;

    cout << answer << '\n';
    return 0;
}