#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double dx = x1 - x2;
    double dy = y1 - y2;
    double d = sqrt(dx*dx + dy*dy);
    double S;

    if(d >= r1 + r2) S = 0;
    else if(d <= abs(r1 - r2)) S = PI * pow(min(r1, r2), 2);
    else {
        double angle1 = 2 * acos((r1*r1 + d*d - r2*r2) / (2*r1*d));
        double angle2 = 2 * acos((r2*r2 + d*d - r1*r1) / (2*r2*d));

        double area1 = 0.5 * r1*r1 * (angle1 - sin(angle1));
        double area2 = 0.5 * r2*r2 * (angle2 - sin(angle2));

        S = area1 + area2;
    }

    cout.precision(3);
    cout << fixed << S << '\n';
    return 0;
}