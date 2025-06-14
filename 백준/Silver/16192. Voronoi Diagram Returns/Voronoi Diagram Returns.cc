#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> coordinate(n);
    for(int i = 0; i < n; i++)
        cin >> coordinate[i].first >> coordinate[i].second;

    while(q--) {
        int qx, qy;
        cin >> qx >> qy;

        int minDist = 1e9;
        vector<int> idx;

        for(int j = 0; j < n; j++) {
            int dx = qx - coordinate[j].first;
            int dy = qy - coordinate[j].second;
            int dist = dx*dx + dy*dy;

            if(dist < minDist) {
                minDist = dist;
                idx = {j};
            }
            else if(dist == minDist) idx.emplace_back(j);
        }

        if(idx.empty()) cout << "NONE" << '\n';
        else if(idx.size() == 1) cout << "REGION" << ' ' << idx[0]+1 << '\n';
        else if(idx.size() == 2) cout << "LINE" << ' ' << idx[0]+1 << ' ' << idx[1]+1 << '\n';
        else cout << "POINT" << '\n';
    }

    return 0;
}