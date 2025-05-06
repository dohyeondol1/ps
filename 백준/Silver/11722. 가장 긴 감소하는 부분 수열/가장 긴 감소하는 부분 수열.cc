#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<int> length(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        length[i] = 1;
    }
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < i; j++)
            if(A[i] < A[j]) length[i] = max(length[i], length[j]+1);
    
    sort(length.begin(), length.end());
    cout << length[N-1] << '\n';
    
    return 0;
}