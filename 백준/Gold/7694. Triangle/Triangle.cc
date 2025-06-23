#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long countEdge(pair<long long, long long> p1, pair<long long, long long> p2){
    long long dx = abs(p2.first - p1.first);
    long long dy = abs(p2.second - p1.second);
    if(dx == 0) return dy;
    return __gcd(dx, dy);
}

long long ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3){
    return abs(p1.first * p2.second + p2.first * p3.second + p3.first * p1.second - p1.second * p2.first - p2.second * p3.first - p3.second * p1.first);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    while (true) {
        pair<long long, long long> a, b, c;
        cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
        if ((a.first | a.second | b.first | b.second | c.first | c.second) == 0) break;
        
        long long A = countEdge(a, b) + countEdge(b, c) + countEdge(c, a);
        long long S = ccw(a, b, c);
        cout << (S - A + 2) / 2 << '\n';
    }
 
    return 0;
}