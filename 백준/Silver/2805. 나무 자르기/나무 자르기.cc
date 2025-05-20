#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long M;

int binary_search(long long target, int L, vector<int> &tree) {
    int left = 0, right = L;

    int answer = 0;
    while(left <= right) {
        int mid = (left+right)/2;
        long long sum = 0;
        
        for(int i = 0; i < N; i++)
            if(tree[i] > mid) sum += tree[i] - mid;
        
        if(sum >= target) {
            answer = mid;
            left = mid+1;
        }
        else right = mid-1;
    }
    
    return answer;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N >> M;
    
    vector<int> height(N);
    for(int i = 0; i < N; i++)
        cin >> height[i];
    
    sort(height.begin(), height.end());
    cout << binary_search(M, height[N-1], height) << '\n';
    
    return 0;
}