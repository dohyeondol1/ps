#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[1000];
int inc_dp[1000];
int dec_dp[1000];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> A[i];

    for(int i = 0; i < N; i++) {
        inc_dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(A[i] > A[j])
                inc_dp[i] = max(inc_dp[i], inc_dp[j] + 1);
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        dec_dp[i] = 1;
        for(int j = N - 1; j > i; j--) {
            if(A[i] > A[j])
                dec_dp[i] = max(dec_dp[i], dec_dp[j] + 1);
        }
    }

    int max_length = 0;
    for(int i = 0; i < N; i++)
        max_length = max(max_length, inc_dp[i] + dec_dp[i] - 1);

    cout << max_length << '\n';
    return 0;
}