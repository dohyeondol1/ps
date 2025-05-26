#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    long long dp[300001] = {0};
    limit -= times[0];

    int i = 0;
    int Max = diffs[0];
    long long sum = 0;
    for(i = 1; i < times.size(); i++){
        limit -= times[i];
        dp[diffs[i]] += times[i] + times[i-1];
        dp[0] += (times[i] + times[i-1]) * (diffs[i] - 1);
        sum += times[i] + times[i-1];
        Max = max(diffs[i], Max);
    }

    if(dp[0] <= limit)
        return 1;

    for(i = 1 ; ; i++){
        sum -= dp[i];
        dp[i] = dp[i-1] - sum;

        if(dp[i] <= limit)
            break;
    }

    return min(Max, i + 1);
}