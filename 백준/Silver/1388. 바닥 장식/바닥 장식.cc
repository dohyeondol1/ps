#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> graph(N, vector<char>(M));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> graph[i][j];

    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == '-') {
                if(j+1 < M && graph[i][j+1] == '-') continue;
                else count++;
            }
            
            if(graph[i][j] == '|') {
                if(i+1 < N && graph[i+1][j] == '|') continue;
                else count++;
            }
        }
    }
    
    cout << count << '\n';
    return 0;
}