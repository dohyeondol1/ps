#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N;
    vector<int> N_array(N);
    for(int i = 0; i < N; i++) {
        cin >> N_array[i];
    }
    
    cin >> M;
    vector<int> M_array(M), count(M);
    for(int i = 0; i < M; i++) {
        cin >> M_array[i];
        count[i] = 0;
    }
    
    sort(N_array.begin(), N_array.end());
    
    for(int i = 0; i < M; i++){
        count[i] += (upper_bound(N_array.begin(), N_array.end(), M_array[i]) - lower_bound(N_array.begin(), N_array.end(), M_array[i]));
    }
    
    for(int i = 0; i < M; i++) {
        cout << count[i];
        if(i != M - 1) cout << " ";
    }

    return 0;
}