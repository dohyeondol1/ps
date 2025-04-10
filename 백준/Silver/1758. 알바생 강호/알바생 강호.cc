#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> tip(N);
    for(int i = 0; i < N; i++) {
        cin >> tip[i];
    }
    
    sort(tip.rbegin(), tip.rend());
    
    long long totalTip = 0;
    for(int i = 0; i < N; i++) {
        if(tip[i]-i < 0) continue;
        totalTip += tip[i]-i;
    }
    
    cout << totalTip << '\n';
    
    return 0;
}