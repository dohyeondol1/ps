#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t, loc = 90;
    for(int i = 0; i < 10; i++) {
        cin >> t;
        if(t == 1) loc -= 90;
        if(t == 2) loc -= 180;
        if(t == 3) loc += 90;
    }

    loc = (loc % 360 + 360) % 360;
    if(loc == 0) cout << "E" << '\n';
    else if(loc == 90) cout << "N" << '\n';
    else if(loc == 180) cout << "W" << '\n';
    else if(loc == 270) cout << "S" << '\n';

    return 0;
}