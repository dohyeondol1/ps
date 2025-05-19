#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    bool isOver = false;
    bool isINF = false;
    
    int N, K;
    cin >> N >> K;
    vector<int> source(N);
    for(int i = 0; i < N; i++) {
        cin >> source[i];
        if(source[i] > K) isOver = true;
        if(source[i] <= 0) isINF = true;
    }
    
    sort(source.begin(), source.end());
    
    long long count = 0;
    for(int i = 1; i < N; i++)
        if(!isINF && !isOver) count += (K - source[i])/source[0];
    
    if(isOver) cout << 0 << '\n';
    else if(isINF) cout << -1 << '\n';
    else cout << count+1 << '\n';

    return 0;
}