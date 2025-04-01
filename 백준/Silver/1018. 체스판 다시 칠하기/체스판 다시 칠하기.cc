#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    char WB[8][8] = {
    	'W','B','W','B','W','B','W','B',
    	'B','W','B','W','B','W','B','W',
    	'W','B','W','B','W','B','W','B',
    	'B','W','B','W','B','W','B','W',
    	'W','B','W','B','W','B','W','B',
    	'B','W','B','W','B','W','B','W',
    	'W','B','W','B','W','B','W','B',
    	'B','W','B','W','B','W','B','W'
    };
    
    char BW[8][8] = {
    	'B','W','B','W','B','W','B','W',
    	'W','B','W','B','W','B','W','B',
    	'B','W','B','W','B','W','B','W',
    	'W','B','W','B','W','B','W','B',
    	'B','W','B','W','B','W','B','W',
    	'W','B','W','B','W','B','W','B',
    	'B','W','B','W','B','W','B','W',
    	'W','B','W','B','W','B','W','B'
    };
    
    int N, M;
    cin >> N >> M;
    int minRepaintBlock;
    int result = 64;
    char ChessBoard[50][50];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> ChessBoard[i][j];
    
    for(int i = 0; i <= N-8; i++) {
        for(int j = 0; j <= M-8; j++) {
            int countBW = 0, countWB = 0;
            for(int y = 0; y < 8; y++) {
                for(int x = 0; x < 8; x++) {
                    if(ChessBoard[i+y][j+x] != BW[y][x]) countBW++;
                    if(ChessBoard[i+y][j+x] != WB[y][x]) countWB++;
                }
            }
            minRepaintBlock = min(countBW, countWB);
            if(result >= minRepaintBlock) result = minRepaintBlock;
        }
    }
    
    cout << result << '\n';
    
    return 0;
}