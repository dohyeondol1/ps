#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, i, arr[51] = { 0, };
    cin >> N;    
    for(int k = 0; k < N; ++k) {
        cin >> i;
        arr[i]++;
    }
    
    int answer = -1;
    if(arr[0] == 0) answer = 0;
    for(int i = 0; i <= N; ++i) {
        if(arr[i] == i) answer = i;
    }
    
    cout << answer << '\n';
    return 0;
}