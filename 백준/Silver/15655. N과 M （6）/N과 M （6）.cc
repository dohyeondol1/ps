#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
bool visited[10001] = { 0, };

void dfs(int num, int count, vector<int> &sequence) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M-1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = num; i < N; i++) {
        if(!visited[sequence[i]]) {
            visited[sequence[i]] = true;
            arr[count] = sequence[i];
            dfs(i+1, count+1, sequence);
            visited[sequence[i]] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    vector<int> arr2(N);
    for(int i = 0; i < N; i++)
        cin >> arr2[i];
    
    sort(arr2.begin(), arr2.end());
    
    dfs(0, 0, arr2);
    return 0;
}