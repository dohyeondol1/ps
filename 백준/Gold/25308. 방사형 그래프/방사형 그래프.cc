#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const double PI = 3.141592;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    vector<int> a(8);
    for(int i = 0; i < 8; i++)
        cin >> a[i];

    vector<int> order = {0, 1, 2, 3, 4, 5, 6, 7};
    double dot[8][2];
    int answer = 0;

    do {
        for(int i = 0; i < 8; i++) {
            double angle = PI * 45 * i/180;
            dot[i][0] = cos(angle) * a[order[i]];
            dot[i][1] = sin(angle) * a[order[i]];
        }

        bool convex = true;
        for(int i = 0; i < 8; i++) {
            int A = i, B = (i+1)%8, C = (i+2)%8;
            double outer = (dot[B][0]-dot[A][0])*(dot[C][1]-dot[A][1]) - (dot[C][0]-dot[A][0])*(dot[B][1]-dot[A][1]);
            if(outer < 0) {
                convex = false;
                break;
            }
        }

        if(convex) answer++;
    } while(next_permutation(order.begin(), order.end()));

    cout << answer << '\n';
    return 0;
}