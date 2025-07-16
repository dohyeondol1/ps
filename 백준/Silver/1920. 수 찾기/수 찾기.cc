#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M;
    cin >> N;
    vector<int> array(N);
    for(int i = 0; i < N; ++i)
        cin >> array[i];
    
    sort(array.begin(), array.end());
    
    cin >> M; int x;
    for(int i = 0; i < M; ++i) {
        cin >> x;
        cout << binary_search(array.begin(), array.end(), x) << '\n';
    }
    
    return 0;
}