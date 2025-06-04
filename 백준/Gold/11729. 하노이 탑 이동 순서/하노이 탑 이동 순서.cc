#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void hanoi(int n, int start, int to, int bypass) {
    if(n == 1) cout << start << ' ' << to << '\n';
    else {
        hanoi(n-1, start, bypass, to);
        cout << start << ' ' << to << '\n';
        hanoi(n-1, bypass, to, start);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    cout << (int)pow(2, N) -1 << '\n';
    hanoi(N, 1, 3, 2);
    
    return 0;
}