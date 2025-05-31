#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string A, B;
    cin >> A >> B;
    sort(A.begin(), A.end());
    
    int answer = 0;
    while(next_permutation(A.begin(), A.end())) {
        int C = stoi(A);
        if(C >= stoi(B) || A[0] == '0') continue;
        else answer = max(answer, C);
    } 
    
    if(answer == 0) cout << -1 << '\n';
    else cout << answer << '\n';
    return 0;
}