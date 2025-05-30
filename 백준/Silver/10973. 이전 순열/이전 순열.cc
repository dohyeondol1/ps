#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> nums(N);
    for(int i = 0; i < N; i++) cin >> nums[i];

    bool able = prev_permutation(nums.begin(), nums.end());
    if(able) {
        for(int i = 0; i < N; i++) {
            cout << nums[i];
            if(i < N-1) cout << ' ';
        }
    } 
    else cout << -1 << '\n';

    return 0;
}