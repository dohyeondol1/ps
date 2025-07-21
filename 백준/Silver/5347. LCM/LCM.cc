#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    long long T, A, B;
    cin >> T;
    long long lcm = 1e9;
    while(T--) {
        cin >> A >> B;
        lcm = A*B / __gcd(A, B);
        cout << lcm << '\n';
    }

    return 0;
}