#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for(int &arr : A)
        cin >> arr;
    
    int minAmount = 0;
    for(int i = 0; i < N; i++){
        if(i+2 < N && A[i+1] > A[i+2]) {
            int minA2 = min(A[i], A[i+1] - A[i+2]);
            minAmount += minA2*5;
            A[i] -= minA2;
            A[i+1] -= minA2;

            int minA3 = min({A[i], A[i+1], A[i+2]});
            minAmount += minA3*7;
            A[i] -= minA3;
            A[i+1] -= minA3;
            A[i+2] -= minA3;
        }    
        else if(i+2 < N) {
            int minA3 = min({A[i], A[i+1], A[i+2]});
            minAmount += minA3*7;
            A[i] -= minA3;
            A[i+1] -= minA3;
            A[i+2] -= minA3;

            int minA2 = min(A[i], A[i+1]);
            minAmount += minA2*5;
            A[i] -= minA2;
            A[i+1] -= minA2;
        }
        else if(i+1 < N) {
            int minA2 = min(A[i], A[i+1]);
            minAmount += minA2*5;
            A[i] -= minA2;
            A[i+1] -= minA2;
        }
        minAmount += A[i]*3;
    }
    
    cout << minAmount << '\n';
    return 0;
}