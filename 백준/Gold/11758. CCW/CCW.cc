#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int crossProduct = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);

    if(crossProduct > 0) cout << 1 << '\n';
    else if(crossProduct < 0) cout << -1 << '\n';
    else cout << 0 << '\n';

    return 0;
}