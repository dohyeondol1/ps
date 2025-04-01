#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N), B(N);
    int scoreA = 0, scoreB = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        if(A[i] > B[i]) scoreA++;
        if(A[i] < B[i]) scoreB++;
    }
    
    cout << scoreA << ' ' << scoreB;
    
    return 0;
}