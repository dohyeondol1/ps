#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> firstDayTrash(N);
    for(int i = 0; i < N; i++)
        cin >> firstDayTrash[i];
    
    vector<int> secondDayTrash(N);
    for(int i = 0; i < N; i++)
        cin >> secondDayTrash[i];
    
    int maxCount = 0;
    vector<int> dp(N+1, 0);
    for(int i = 0; i < N; i++) {
        int count = 0; 
        for(int j = 0; j < N; j++) {
            if(firstDayTrash[i] == secondDayTrash[j]) dp[j] = max(dp[j], count+1);
            if(firstDayTrash[i] > secondDayTrash[j] && dp[j] > count) count = dp[j];
            maxCount = max(maxCount, dp[j]);
        }
    }
    
    cout << maxCount << '\n';
    return 0;
}