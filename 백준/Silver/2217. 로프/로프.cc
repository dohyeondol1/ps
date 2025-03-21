#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> ropes(N);
    
    for (int i = 0; i < N; i++) {
        cin >> ropes[i];
    }

    sort(ropes.rbegin(), ropes.rend());

    int maxWeight = 0;

    for (int i = 0; i < N; i++) {
        maxWeight = max(maxWeight, ropes[i] * (i + 1));
    }

    cout << maxWeight;

    return 0;
}