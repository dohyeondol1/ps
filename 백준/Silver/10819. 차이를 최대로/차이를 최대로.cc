#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> nums(N);
    for(int i = 0; i < N; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    
    int answer = 0;
    do {
        int temp = 0;
        for(int i = 0; i < N-1; i++) 
            temp += abs(nums[i] - nums[i+1]);
        answer = max(answer, temp);
    } while(next_permutation(nums.begin(), nums.end()));
    
    cout << answer << '\n';
    return 0;
}