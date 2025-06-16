#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
using namespace std;

int N;
int parent[3001];

int getParent(int x) {
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a != b) {
        if(a < b) parent[b] = a;
        else parent[a] = b;
    }
}

int ccw(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c) {
    long long outer = (long long)(b.first - a.first) * (c.second - a.second) - (long long)(c.first - a.first) * (b.second - a.second);
    if(outer < 0) return -1;
    else if(outer > 0) return 1;
    else return 0;
}

bool isOverlapping(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    return !(b < c || d < a);
}

bool isIntersecting(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);
    
    if(abc * abd < 0 && cda * cdb < 0) return true;
    
    if(abc * abd <= 0 && cda * cdb <= 0) {
        if(max(min(a.first, b.first), min(c.first, d.first)) <= min(max(a.first, b.first), max(c.first, d.first)) && max(min(a.second, b.second), min(c.second, d.second)) <= min(max(a.second, b.second), max(c.second, d.second))) {
            return true;
        }
    }
    
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    
    vector<tuple<int, int, int, int>> line(N);
    
    for(int i = 0; i < N; i++) {
        cin >> get<0>(line[i]) >> get<1>(line[i]) >> get<2>(line[i]) >> get<3>(line[i]);
        parent[i] = i;
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            pair<int, int> a, b, c, d;
            a = {get<0>(line[i]), get<1>(line[i])};
            b = {get<2>(line[i]), get<3>(line[i])};
            c = {get<0>(line[j]), get<1>(line[j])};
            d = {get<2>(line[j]), get<3>(line[j])};
            
            if(isIntersecting(a, b, c, d)) unionParent(i, j);
        }
    }
    
    map<int, int> groupSize;
    for(int i = 0; i < N; i++) {
        int root = getParent(i);
        groupSize[root]++;
    }
    
    int maxSize = 0;
    for(auto& p : groupSize)
        maxSize = max(maxSize, p.second);
    
    cout << groupSize.size() << '\n';
    cout << maxSize << '\n';
    
    return 0;
}