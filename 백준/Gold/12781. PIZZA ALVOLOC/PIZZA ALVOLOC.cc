#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
    long long outer = a.first*b.second + b.first*c.second + c.first*a.second - (a.first*c.second + b.first*a.second + c.first*b.second);
                        
    if(outer > 0) return 1;
    else if(outer == 0) return 0;
    else if(outer < 0) return -1;
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    pair<long long, long long> a;
    pair<long long, long long> b;
    pair<long long, long long> c;
    pair<long long, long long> d;
    
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
    
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);
    
    if(abc * abd < 0 && cda * cdb < 0) cout << 1;
    else cout << 0;
    
    return 0;
}