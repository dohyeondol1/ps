#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> nums(N);
    for(int i = 0; i < N; i++)
        nums[i] = i+1;

    do {
    for(int i = 0; i < N; i++) {
            cout << nums[i];
            if(i < N-1) cout << ' ';
        }
        cout << '\n';
    } while(next_permutation(nums.begin(), nums.end()));

    return 0;
}