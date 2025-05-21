#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int S, C, O, N;
    cin >> S >> C >> O >> N;

    S += N;
    C += O*2;
    int cCount = C/6;
    int sCount = S/3;

    cout << min(sCount, cCount) << '\n';
    return 0;
}