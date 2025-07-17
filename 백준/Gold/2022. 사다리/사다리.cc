#include <iostream>
#include <cmath>
using namespace std;

double x, y, c, answer = 0;

double func(double &mid){
    double h1 = sqrt(x*x - mid*mid);
    double h2 = sqrt(y*y - mid*mid);
    
    return (h1 * h2)/(h1 + h2);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.precision(3);
    cout << fixed;
    
    cin >> x >> y >> c;
    double low = 0, high = min(x, y);
    while(high - low > 0.000001) {
        double mid = (low + high) / 2.0;
        
        if(func(mid) >= c){
            answer = mid;
            low = mid;
        }
        else
            high = mid;
    }
    
    cout << answer << '\n';
    return 0;
}