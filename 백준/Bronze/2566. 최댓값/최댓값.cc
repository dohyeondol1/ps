#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    vector<vector<int>> matrix(9, vector<int> (9));
    int maxNum = -1;
    pair<int, int> answer;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] > maxNum) {
                maxNum = matrix[i][j];
                answer.first = i+1;
                answer.second = j+1;
            }
        }
    }
    
    cout << maxNum << '\n';
    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}