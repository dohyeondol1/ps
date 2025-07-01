#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int P, T, X, Y;
    cin >> P;
    while(P--) {
        cin >> T >> X >> Y;
        cout << T << ' ';

        if(X < Y) {
            cout << 2 << ' ' << X << ' ' << Y;
        }
        else if(Y >= 4) {
            cout << 6 << ' ' << 1 << ' ' << 2 << ' ' << 3 << ' ';
            cout << X-Y+5 << ' ' << X+2 << ' ' << X+3;
        }
        else
            cout << "NO PATH";

        cout << '\n';
    }

    return 0;
}