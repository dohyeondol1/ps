#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    long long x, y;
    int idx;
};

Point base;

long long crossProduct(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

long long distanceSquared(const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool angleSort(const Point& a, const Point& b) {
    long long cross = crossProduct(base, a, b);
    if (cross != 0) return cross > 0;
    return distanceSquared(base, a) < distanceSquared(base, b);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    vector<Point> points(N);
    for(int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
        points[i].idx = i;
    }
    
    int baseIdx = 0;
    for(int i = 1; i < N; ++i) {
        if(points[i].y < points[baseIdx].y || (points[i].y == points[baseIdx].y && points[i].x < points[baseIdx].x))
            baseIdx = i;
    }
    
    swap(points[0], points[baseIdx]);
    base = points[0];
    
    sort(points.begin() + 1, points.end(), angleSort);
    
    vector<Point> hull;
    for(int i = 0; i < N; ++i) {
        while(hull.size() >= 2) {
            if(crossProduct(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0)
                hull.pop_back();
            else
                break;
        }
        hull.push_back(points[i]);
    }
    
    cout << hull.size() << '\n';
    return 0;
}