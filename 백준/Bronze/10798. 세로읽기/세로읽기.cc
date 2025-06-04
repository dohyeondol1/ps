#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    vector<vector<char>> input(5, vector<char> (15, '#'));
    string row;
    for(int i = 0; i < 5; i++) {
        getline(cin, row);
        for(int j = 0; j < row.length(); j++)
            input[i][j] = row[j];
    }
    
    for(int i = 0; i < input[0].size(); i++) {
        for(int j = 0; j < 5; j++) {
            if(input[j][i] == '#') continue;
            else cout << input[j][i];
        }
    }

    return 0;
}