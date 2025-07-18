#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N; cin >> N;
    vector<int> arr(N);
    for(int& x : arr) cin >> x;

    vector<int> count(N+1, 0);
    for(int x : arr)
        if (x <= N) count[x]++;

    int answer = -1;
    for(int k = 0; k <= N; ++k)
        if(count[k] == k) answer = k;

    cout << answer << '\n';
    return 0;
}