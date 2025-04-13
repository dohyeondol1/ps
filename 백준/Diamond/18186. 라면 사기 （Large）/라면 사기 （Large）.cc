#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    long long N, B, C;
    cin >> N >> B >> C;
    vector<long long> A(N);
    for(long long &arr : A)
        cin >> arr;
    
    long long minAmount = 0;
    if(B < C) {
        for(int i = 0; i < N; i++)
            minAmount += A[i]*B;
        cout << minAmount << '\n';
        return 0;
    }
    
    for(int i = 0; i < N; i++){
        if(i+2 < N && A[i+1] > A[i+2]) {
            long long minA2 = min(A[i], A[i+1] - A[i+2]);
            minAmount += minA2*(B+C);
            A[i] -= minA2;
            A[i+1] -= minA2;

            long long minA3 = min({A[i], A[i+1], A[i+2]});
            minAmount += minA3*(B+(2*C));
            A[i] -= minA3;
            A[i+1] -= minA3;
            A[i+2] -= minA3;
        }    
        else if(i+2 < N) {
            long long minA3 = min({A[i], A[i+1], A[i+2]});
            minAmount += minA3*(B+(2*C));
            A[i] -= minA3;
            A[i+1] -= minA3;
            A[i+2] -= minA3;

            long long minA2 = min(A[i], A[i+1]);
            minAmount += minA2*(B+C);
            A[i] -= minA2;
            A[i+1] -= minA2;
        }
        else if(i+1 < N) {
            long long minA2 = min(A[i], A[i+1]);
            minAmount += minA2*(B+C);
            A[i] -= minA2;
            A[i+1] -= minA2;
        }
        minAmount += A[i]*B;
    }
    
    cout << minAmount << '\n';
    return 0;
}