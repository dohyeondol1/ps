#include <iostream>
using namespace std;

int N, M;
int arr[9] = { 0, };
bool visited[9] = { 0, };

void dfs(int num, int count) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M-1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = num; i <= N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            arr[count] = i;
            dfs(i+1, count+1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    
    dfs(1, 0);
    return 0;
}