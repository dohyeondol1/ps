#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto& i : A)
        cin >> i;

    vector<int> length(N);
    for(int i = 0; i < N; i++)
        length[i] = 1;

    for(int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            if(A[i] > A[j])
                length[i] = max(length[i], length[j]+1);
    
    sort(length.begin(), length.end());
    
    cout << length[N-1] << '\n';
    
    return 0;
}