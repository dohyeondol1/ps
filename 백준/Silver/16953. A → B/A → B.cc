#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

    int A, B, count = 0;
    cin >> A >> B;
    
    while(B > A) {
        if(B%2 == 0) {
            B /= 2;
            count++;
        }
        else if(B%10 == 1) {
            B--;
            B /= 10;
            count++;
        }
        else break;
    }
    if(B != A) cout << -1 << '\n';
    else cout << count+1 << '\n';

    return 0;
}