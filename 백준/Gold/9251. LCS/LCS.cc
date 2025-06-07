#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string str1,str2;
    cin >> str1 >> str2;

    int str1Length = str1.length();
    int str2Length = str2.length();

    for(int i = 1; i <= str1Length; i++){
        for(int j = 1; j <= str2Length; j++){
            char curChar1 = str1[i-1];
            char curChar2 = str2[j-1];

            if(curChar1 == curChar2) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    cout << dp[str1Length][str2Length] << '\n';
    return 0;
}