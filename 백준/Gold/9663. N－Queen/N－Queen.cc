#include <iostream>
using namespace std;

int N;
int result = 0;
int column[15];

bool isPromising(int currentRow) {
    for(int prevRow = 0; prevRow < currentRow; prevRow++) {
        if(column[prevRow] == column[currentRow] || abs(column[currentRow] - column[prevRow]) == currentRow - prevRow) {
            return false;
        }
    }
    return true;
}

void NQueens(int row) {
    if(row == N) {
        result++;
        return;
    }
    
    for(int i = 0; i < N; i++) {
        column[row] = i;
        if(isPromising(row)) {
            NQueens(row + 1);
        }
    }
}

int main() {
    cin >> N;
    NQueens(0);
    cout << result << endl;
    return 0;
}