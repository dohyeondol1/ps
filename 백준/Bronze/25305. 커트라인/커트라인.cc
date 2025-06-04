#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, k;
    cin >> N >> k;
    vector<int> score(N);
    for(int i = 0; i < N; i++)
        cin >> score[i];
    
    sort(score.rbegin(), score.rend());
    cout << score[k-1] << '\n';
    return 0;
}