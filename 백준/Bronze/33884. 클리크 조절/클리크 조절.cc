#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<pair<long long, long long>> shoot(N);
    vector<pair<long long, long long>> arrive(N);
    
    for(auto &sh : shoot)
        cin >> sh.first >> sh.second;
    
    for(auto &ar : arrive)
        cin >> ar.first >> ar.second;
    
    sort(shoot.begin(), shoot.end());
    sort(arrive.begin(), arrive.end());
    int x = arrive[0].first - shoot[0].first;
    int y = arrive[0].second - shoot[0].second;
    
    cout << x << ' ' << y << '\n';

    return 0;
}