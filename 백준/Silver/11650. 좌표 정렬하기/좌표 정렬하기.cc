#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<pair<int,int>> coordinate;
    
    int x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        coordinate.push_back(make_pair(x, y));
    }
    
    sort(coordinate.begin(), coordinate.end());
    
    for (const auto& p : coordinate) {
        cout << p.first << ' ' << p.second << '\n';
    }
    
    return 0;
}