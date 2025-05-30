#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    double A, B;
    cin >> A >> B;
    
    cout.precision(16);
    cout << A/B << '\n';
    
    return 0;
}