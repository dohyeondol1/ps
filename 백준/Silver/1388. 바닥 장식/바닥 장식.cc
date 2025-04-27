#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> graph(N, vector<char>(M));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == '-') {
                if(j+1 < M && graph[i][j+1] == '-') continue;
                else count++;
            }
        }
    }
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[j][i] == '|') {
                if(j+1 < N && graph[j+1][i] == '|') continue;
                else count++;
            }
        }
    }
    
    cout << count << '\n';
    return 0;
}