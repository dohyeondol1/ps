#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T, x1, y1, x2, y2, x, y, n, IOcount = 0;
    cin >> T;
    while(T--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n, IOcount = 0;
        cin >> n;

        for(int i = 0; i < n; i++) {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            bool startIn = (pow(cx-x1, 2) + pow(cy-y1, 2)) < r*r;
            bool endIn = (pow(cx-x2, 2) + pow(cy-y2, 2)) < r*r;

            if(startIn != endIn) IOcount++;
        }
        
        cout << IOcount << '\n';
    }

    return 0;
}