#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
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

    string a = to_string(pow(2, N));
    int x = a.find('.');
    a = a.substr(0, x);
    a[a.length() - 1] -= 1;

    cout << a << '\n';

    if(N <= 20) hanoi(N, 1, 3, 2);

    return 0;
}