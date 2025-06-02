#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    int d, maxD = 0;
    for(int i = 0; i < N; i++) {
        d = A[i].second - i;
        if(d > maxD) maxD = d;
    }

    cout << maxD+1 << '\n';
    return 0;
}