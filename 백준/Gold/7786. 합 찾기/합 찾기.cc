#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long long dp[11][2][100];
vector<int> digitVec;

long long digitSum(int pos, int tight, int sum) {
    if(pos == digitVec.size()) return sum;

    long long& result = dp[pos][tight][sum];
    if(result != -1) return result;
    result = 0;

    int limit;
    if(tight == 1)
        limit = digitVec[pos];
    else
        limit = 9;

    for(int d = 0; d <= limit; ++d) {
        int nextTight;
        if(tight == 1 && d == limit)
            nextTight = 1;
        else
            nextTight = 0;

        result += digitSum(pos + 1, nextTight, sum + d);
    }

    return result;
}

long long getSum(long long n) {
    digitVec.clear();
    while(n > 0) {
        digitVec.push_back(n % 10);
        n /= 10;
    }
    if (digitVec.empty()) digitVec.push_back(0);
    reverse(digitVec.begin(), digitVec.end());
    memset(dp, -1, sizeof(dp));
    return digitSum(0, 1, 0);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long lower, upper;
    cin >> lower >> upper;

    long long sumUpper = getSum(upper);
    long long sumLowerMinus1 = getSum(lower - 1);

    cout << sumUpper - sumLowerMinus1 << '\n';
    return 0;
}