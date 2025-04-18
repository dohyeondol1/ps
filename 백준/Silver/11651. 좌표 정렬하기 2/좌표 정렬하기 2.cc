#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> coordinate(N);
    for(int i = 0; i < N; i++)
        cin >> coordinate[i].second >> coordinate[i].first;
    
    sort(coordinate.begin(), coordinate.end());
    for(int i = 0; i < N; i++) {
        cout << coordinate[i].second << ' ' << coordinate[i].first;
        if(i < N-1) cout << '\n';
    }
    
    return 0;
}