#include <iostream>
using namespace std;

int N, M;
int arr[9] = { 0, };

void dfs(int count) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M-1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++) {
        arr[count] = i;
        dfs(count+1);
    }
}

int main() {
    cin >> N >> M;
    
    dfs(0);
    return 0;
}