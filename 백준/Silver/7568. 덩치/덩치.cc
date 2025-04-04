#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, rank = 1;
    cin >> N;
    
    vector<pair<int, int>> size(N);
    for(int i = 0; i < N; i++) {
        cin >> size[i].first >> size[i].second;
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(size[i].first < size[j].first && size[i].second < size[j].second)
                rank++;
        }
        cout << rank << " ";
        rank = 1;
    }
    
    return 0;
}