#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[101][101] = { 0, };

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, count = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        for(int i = y; i < y+10; i++)
            for(int j = x; j < x+10; j++)
                if(board[i][j] == 1) count++;
                else board[i][j] = 1;
    }
    
    cout << N*100 - count << '\n';
    
    return 0;
}