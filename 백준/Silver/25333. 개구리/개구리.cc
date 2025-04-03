#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int A, B, X;
        cin >> A >> B >> X;
        int gcd = __gcd(A, B);
        cout << X/gcd << '\n';
    }

    return 0;
}