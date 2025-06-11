#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int xA, yA, xB, yB, xC, yC;
    cin >> xA >> yA >> xB >> yB >> xC >> yC;
    double S = abs(xA*(yB-yC) + xB*(yC-yA) + xC*(yA-yB)) / 2.0;
    
    int N, x, y, count = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        double s1 = abs(x*(yB-yC) + xB*(yC-y) + xC*(y-yB)) / 2.0;
        double s2 = abs(xA*(y-yC) + x*(yC-yA) + xC*(yA-y)) / 2.0;
        double s3 = abs(xA*(yB-y) + xB*(y-yA) + x*(yA-yB)) / 2.0;
        if(s1+s2+s3 == S) count++;
    }
    
    cout << fixed << setprecision(1) << S << '\n' << count << '\n';
    return 0;
}