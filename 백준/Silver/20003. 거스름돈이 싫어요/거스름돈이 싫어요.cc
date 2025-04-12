#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    long long A, B, otherA, otherB;
    cin >> N >> A >> B;

    long long g = __gcd(A, B);
    A /= g;
    B /= g;

    while(--N) {
        cin >> otherA >> otherB;

        g = __gcd(otherA, otherB);
        otherA /= g;
        otherB /= g;
        A = __gcd(A, otherA);
        B = B / __gcd(B, otherB) * otherB;
    }

    cout << A << " " << B;
    return 0;
}