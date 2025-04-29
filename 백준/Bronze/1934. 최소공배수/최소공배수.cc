#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T, A, B;
    cin >> T;
    vector<int> lcm(T);
    for(int i = 0; i < T; i++) {
        cin >> A >> B;
        lcm[i] = A*B / __gcd(A, B);
    }
    
    for(auto &answer : lcm)
        cout << answer << '\n';

    return 0;
}