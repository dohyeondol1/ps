#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M;
    cin >> N;
    
    vector<int> N_array(N);
    for(int i = 0; i < N; i++)
        cin >> N_array[i];

    sort(N_array.begin(), N_array.end());
    
    cin >> M; int x;
    for(int i = 0; i < M; i++) {
        cin >> x;
        cout << binary_search(N_array.begin(), N_array.end(), x) << '\n';
    }

    return 0;
}