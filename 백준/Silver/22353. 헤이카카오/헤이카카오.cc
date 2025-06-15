#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    long double a, d, k;
    cin >> a >> d >> k;
    long double winProb = d/100, loseProb = 1;
    long double factor = 1 + k/100, result = 0;
    for(int i = 1; ; i++) {
        result += i*a * winProb * loseProb;
        loseProb *= (1-winProb);
        winProb *= factor;
        if(winProb >= 1) {
            result += (i+1)*a * loseProb;
            break;
        }
    }
    
    cout.precision(7);
    cout << fixed << result << '\n';
    return 0;
}