#include <iostream>
#include <vector>
using namespace std;

int T, M, N, K, x, y;
int board[50][50];
int xpos[4] = {0, 0, -1, 1};
int ypos[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
    board[x][y] = 0;
	for(int i = 0; i < 4; i++) {
		int xx = x + xpos[i];
		int yy = y + ypos[i];
		if(xx < 0 || yy < 0 || xx >= M || yy >= N) continue;
		if(board[xx][yy] == 1) {
			dfs(xx, yy);
		}
	}
}

int main() {
    cin >> T;
	while(T--) {
	    int wormCount = 0;
		cin >> M >> N >> K;
		for(int i = 0; i < K; i++) {
			cin >> x >> y;
			board[x][y] = 1;
		}

		for(int i = 0; i < M; i++) {
			for(int j = 0; j < N; j++) {
				if(board[i][j] == 1) {
					dfs(i, j);
					wormCount++;
				}
			}
		}

		cout << wormCount << '\n';
		for(int i = 0; i < M; i++)
			fill(board[i], board[i]+N, 0);
	}
}