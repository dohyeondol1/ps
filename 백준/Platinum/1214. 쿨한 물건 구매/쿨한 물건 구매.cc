#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int D, P, Q;
    cin >> D >> P >> Q;
    
    if(P<Q) swap(P, Q);
    
    int MIN = P;
    for(int i = 0; i <= min(D/P, Q); i++)
        MIN = min(MIN, (Q-(D-P*i)%Q)%Q);
    MIN = min(MIN, (P-(D%P))%P);
    
    cout << D+MIN << '\n';
    return 0;
}