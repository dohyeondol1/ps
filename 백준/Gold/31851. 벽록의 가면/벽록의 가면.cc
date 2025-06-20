#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3) {
    long long outer = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second) - (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
    
    if(outer > 0) return 1;
    else if(outer < 0) return -1;
    else return 0;
}

bool isConvex(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c, pair<long long, long long> d) {
    if(a == b || a == c || a == d || b == c || b == d || c == d) return false;
    if(ccw(a, b, c) == 0 || ccw(b, c, d) == 0 || ccw(c, d, a) == 0 || ccw(d, a, b) == 0) return false;
    
    int ccw1 = ccw(a, b, c);
    int ccw2 = ccw(b, c, d);
    int ccw3 = ccw(c, d, a);
    int ccw4 = ccw(d, a, b);
    
    return (ccw1 > 0 && ccw2 > 0 && ccw3 > 0 && ccw4 > 0) || (ccw1 < 0 && ccw2 < 0 && ccw3 < 0 && ccw4 < 0);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<pair<long long, long long>> pt(N); 
    for(int i = 0; i < N; ++i)
        cin >> pt[i].first >> pt[i].second;
    
    int cnt = 0;
    
    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j < N; ++j) {
            for(int k = j + 1; k < N; ++k) {
                for(int l = k + 1; l < N; ++l) {
                    vector<pair<long long, long long>> points = {pt[i], pt[j], pt[k], pt[l]};
                    
                    sort(points.begin(), points.end());
                    bool found = false;
                    do {
                        if(isConvex(points[0], points[1], points[2], points[3])) {
                            cnt++;
                            break;
                        }
                    } while(next_permutation(points.begin(), points.end()));
                }
            }
        }
    }
    
    cout << cnt << '\n';
    return 0;
}