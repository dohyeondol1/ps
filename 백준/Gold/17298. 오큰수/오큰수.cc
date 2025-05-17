#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    int N;
    cin >> N;
    
    vector<int> arr(N);
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    vector<int> NGE(N, -1);
    stack<int> s;
    s.push(0);
    for(int i = 1; i < N; i++) {
        while(!s.empty() && arr[s.top()] < arr[i]) {
            NGE[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    
    for(int i = 0; i < N; i++) {
        cout << NGE[i];
        if(i < N-1) cout << ' ';
    }
    
    return 0;
}