#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

pair<long double, long double> a, b, c, d, z;
bool isParallel;

long double minVal(long double x, long double y) { return x < y ? x : y; }
long double maxVal(long double x, long double y) { return x > y ? x : y; }
bool isSame(pair<long double, long double> p1, pair<long double, long double> p2) { 
    return p1.first == p2.first && p1.second == p2.second; 
}

int ccw(pair<long double, long double> p1, pair<long double, long double> p2, pair<long double, long double> p3) {
    long double outer = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second) - (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
    
    if(outer == 0) return 0;
    else if(outer > 0) return 1;
    else return -1;
}

bool isIntersecting() {
    if(a.second == b.second)
        return minVal(a.first, b.first) <= maxVal(c.first, d.first) && minVal(c.first, d.first) <= maxVal(a.first, b.first);
    else
        return minVal(a.second, b.second) <= maxVal(c.second, d.second) && minVal(c.second, d.second) <= maxVal(a.second, b.second);
}

bool isValidIntersection() {
    if(a.second == b.second)
        return minVal(a.first, b.first) == maxVal(c.first, d.first) || maxVal(a.first, b.first) == minVal(c.first, d.first);
    else
        return minVal(a.second, b.second) == maxVal(c.second, d.second) || maxVal(a.second, b.second) == minVal(c.second, d.second);
}

void calculateIntersection() {
    double t, x, y;
    t = ((c.first - a.first) * (d.second - c.second) - (c.second - a.second) * (d.first - c.first)) / ((b.first - a.first) * (d.second - c.second) - (b.second - a.second) * (d.first - c.first));
    x = a.first + t * (b.first - a.first);
    y = a.second + t * (b.second - a.second);
    cout << "1" << '\n';
    cout << fixed;
    cout.precision(10);
    cout << x << " " << y << '\n';
}

void printPoint() {
    pair<long double, long double> intersection = (isSame(a, c) || isSame(a, d)) ? a : (isSame(b, c) || isSame(b, d)) ? b : z;
    cout << "1" << '\n';
    cout << intersection.first << " " << intersection.second << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> a.first >> a.second >> b.first >> b.second;
    cin >> c.first >> c.second >> d.first >> d.second;

    int ccw1 = ccw(a, b, c);
    int ccw2 = ccw(a, b, d);
    int ccw3 = ccw(c, d, a);
    int ccw4 = ccw(c, d, b);
    isParallel = !ccw1 && !ccw2;

    if((ccw1 == ccw2 || ccw3 == ccw4) && !isParallel)
        cout << "0" << '\n';
    else if(!isParallel)
        calculateIntersection();
    else if(!isIntersecting())
        cout << "0" << '\n';
    else if(isValidIntersection())
        printPoint();
    else
        cout << "1" << '\n';
    
    return 0;
}