#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    double x_A, y_A, x_B, y_B, x_C, y_C;
    double length_AB, length_AC, length_BC;
    double square[3] = { 0 };

    cin >> x_A >> y_A >> x_B >> y_B >> x_C >> y_C;

    double cross = (x_B - x_A) * (y_C - y_B) - (y_B - y_A) * (x_C - x_B);
    if(fabs(cross) < 1e-9) {
        cout << "-1.0";
        return 0;
    }

    length_AB = sqrt((x_A - x_B) * (x_A - x_B) + (y_A - y_B) * (y_A - y_B));
    length_AC = sqrt((x_A - x_C) * (x_A - x_C) + (y_A - y_C) * (y_A - y_C));
    length_BC = sqrt((x_B - x_C) * (x_B - x_C) + (y_B - y_C) * (y_B - y_C));

    square[0] = (length_AB + length_AC) * 2;
    square[1] = (length_AB + length_BC) * 2;
    square[2] = (length_AC + length_BC) * 2;

    sort(square, square + 3);

    cout << fixed;
    cout.precision(16);
    cout << square[2] - square[0];

    return 0;
}