#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, A = -1;
    cin >> N;
    while(N--) {
        A += 2;
        cout << A << " ";
    }
    return 0;
}