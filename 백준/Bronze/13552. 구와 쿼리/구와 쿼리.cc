#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

using ld = long double;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M;
    cin >> N;
    vector<tuple<long, long, long>> coordinate(N);
    for(int i = 0; i < N; i++)
        cin >> get<0>(coordinate[i]) >> get<1>(coordinate[i]) >> get<2>(coordinate[i]);
    
    cin >> M;
    while(M--) {
        long x, y, z, r;
        int cnt = 0;
        cin >> x >> y >> z >> r;
        
        for(int i = 0; i < N; i++) {
            long dx = x-get<0>(coordinate[i]);
            long dy = y-get<1>(coordinate[i]);
            long dz = z-get<2>(coordinate[i]);
            if(dx*dx + dy*dy + dz*dz <= r*r) cnt++;
        }
        
        cout << cnt << '\n';
    }
    
    return 0;
}