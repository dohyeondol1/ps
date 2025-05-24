#include <iostream>
#include <numeric>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long A, B;
    cin >> A >> B;
    
    cout << A*B / __gcd(A, B);
    
    return 0;
}