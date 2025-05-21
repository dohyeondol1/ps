#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int testCase, n;
    string command;
    bool clockwise = true;
    
    cin >> testCase;
    while(testCase--) {
        char cube[6][3][3] = { { {'w', 'w', 'w'}, {'w', 'w', 'w'}, {'w', 'w', 'w'} },
                       { {'y', 'y', 'y'}, {'y', 'y', 'y'}, {'y', 'y', 'y'} },
                       { {'g', 'g', 'g'}, {'g', 'g', 'g'}, {'g', 'g', 'g'} },
                       { {'r', 'r', 'r'}, {'r', 'r', 'r'}, {'r', 'r', 'r'} },
                       { {'b', 'b', 'b'}, {'b', 'b', 'b'}, {'b', 'b', 'b'} },
                       { {'o', 'o', 'o'}, {'o', 'o', 'o'}, {'o', 'o', 'o'} } };
        char temp;
        
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> command;
            if(command[1] == '+') clockwise = true;
            if(command[1] == '-') clockwise = false;
            
            // U+
            if(command[0] == 'U' && clockwise) {
                for(int i = 0; i < 3; i++) {
                    temp = cube[2][0][i];
                    cube[2][0][i] = cube[3][0][i];
                    cube[3][0][i] = cube[4][0][i];
                    cube[4][0][i] = cube[5][0][i];
                    cube[5][0][i] = temp;
                }
                for(int i = 0; i < 2; i++) {
                    temp = cube[0][i][2];
                    cube[0][i][2] = cube[0][0][i];
                    cube[0][0][i] = cube[0][2-i][0];
                    cube[0][2-i][0] = cube[0][2][2-i];
                    cube[0][2][2-i] = temp;
                }
            }
            // U-
            else if(command[0] == 'U' && !clockwise) {
                for(int i = 0; i < 3; i++) {
                    temp = cube[5][0][i];
                    cube[5][0][i] = cube[4][0][i];
                    cube[4][0][i] = cube[3][0][i];
                    cube[3][0][i] = cube[2][0][i];
                    cube[2][0][i] = temp;
                }
                for(int i = 0; i < 2; i++) {
                    temp = cube[0][0][i];
                    cube[0][0][i] = cube[0][i][2];
                    cube[0][i][2] = cube[0][2][2-i];
                    cube[0][2][2-i] = cube[0][2-i][0];
                    cube[0][2-i][0] = temp;
                }
            }
            
            // D+
            if(command[0] == 'D' && clockwise) {
                for(int i = 0; i < 3; i++) {
                    temp = cube[5][2][i];
                    cube[5][2][i] = cube[4][2][i];
                    cube[4][2][i] = cube[3][2][i];
                    cube[3][2][i] = cube[2][2][i];
                    cube[2][2][i] = temp;
                }
                for(int i = 0; i < 2; i++) {
                    temp = cube[1][i][2];
                    cube[1][i][2] = cube[1][0][i];
                    cube[1][0][i] = cube[1][2-i][0];
                    cube[1][2-i][0] = cube[1][2][2-i];
                    cube[1][2][2-i] = temp;
                }
            }
            // D-
            else if(command[0] == 'D' && !clockwise) {
                for(int i = 0; i < 3; i++) {
                    temp = cube[2][2][i];
                    cube[2][2][i] = cube[3][2][i];
                    cube[3][2][i] = cube[4][2][i];
                    cube[4][2][i] = cube[5][2][i];
                    cube[5][2][i] = temp;
                }
                for(int i = 0; i < 2; i++) {
                    temp = cube[1][0][i];
                    cube[1][0][i] = cube[1][i][2];
                    cube[1][i][2] = cube[1][2][2-i];
                    cube[1][2][2-i] = cube[1][2-i][0];
                    cube[1][2-i][0] = temp;
                }
            }
            
            // F+
            if(command[0] == 'F' && clockwise) {
                for(int i = 0; i < 3; i++) {
                    temp = cube[4][i][0];
                    cube[4][i][0] = cube[0][2][i];
                    cube[0][2][i] = cube[2][2-i][2];
                    cube[2][2-i][2] = cube[1][0][2-i];
                    cube[1][0][2-i] = temp;
                }
                for(int i = 0; i < 2; i++) {
                    temp = cube[3][i][2];
                    cube[3][i][2] = cube[3][0][i];
                    cube[3][0][i] = cube[3][2-i][0];
                    cube[3][2-i][0] = cube[3][2][2-i];
                    cube[3][2][2-i] = temp;
                }
            }
            // F-
            else if(command[0] == 'F' && !clockwise) {
                for(int i = 0; i < 3; i++) {
                    temp = cube[1][0][2-i];
                    cube[1][0][2-i] = cube[2][2-i][2];
                    cube[2][2-i][2] = cube[0][2][i];
                    cube[0][2][i] = cube[4][i][0];
                    cube[4][i][0] = temp;
                }
                for(int i = 0; i < 2; i++) {
                    temp = cube[3][0][i];
                    cube[3][0][i] = cube[3][i][2];
                    cube[3][i][2] = cube[3][2][2-i];
                    cube[3][2][2-i] = cube[3][2-i][0];
                    cube[3][2-i][0] = temp;
                }
            }
            
            // B+
            if(command[0] == 'B' && clockwise) {
                for(int i = 0; i < 3; i++) {
                    temp = cube[1][2][2-i];
                    cube[1][2][2-i] = cube[2][2-i][0];
                    cube[2][2-i][0] = cube[0][0][i];
                    cube[0][0][i] = cube[4][i][2];
                    cube[4][i][2] = temp;
                }
                for(int i = 0; i < 2; i++) {
                    temp = cube[5][i][2];
                    cube[5][i][2] = cube[5][0][i];
                    cube[5][0][i] = cube[5][2-i][0];
                    cube[5][2-i][0] = cube[5][2][2-i];
                    cube[5][2][2-i] = temp;
                }
            }
            // B-
            else if(command[0] == 'B' && !clockwise) {
                for(int i = 0; i < 3; i++) {
                    temp = cube[4][i][2];
                    cube[4][i][2] = cube[0][0][i];
                    cube[0][0][i] = cube[2][2-i][0];
                    cube[2][2-i][0] = cube[1][2][2-i];
                    cube[1][2][2-i] = temp;
                }
                for(int i = 0; i < 2; i++) {
                    temp = cube[5][0][i];
                    cube[5][0][i] = cube[5][i][2];
                    cube[5][i][2] = cube[5][2][2-i];
                    cube[5][2][2-i] = cube[5][2-i][0];
                    cube[5][2-i][0] = temp;
                }
            }
            
            // L+
            if(command[0] == 'L' && clockwise) {
                for(int i = 0; i < 3; i++) {
                    temp = cube[5][2-i][2];
                    cube[5][2-i][2] = cube[1][i][0];
                    cube[1][i][0] = cube[3][i][0];
                    cube[3][i][0] = cube[0][i][0];
                    cube[0][i][0] = temp;
                }
                for(int i = 0; i < 2; i++) {
                    temp = cube[2][i][2];
                    cube[2][i][2] = cube[2][0][i];
                    cube[2][0][i] = cube[2][2-i][0];
                    cube[2][2-i][0] = cube[2][2][2-i];
                    cube[2][2][2-i] = temp;
                }
            }
            // L-
            else if(command[0] == 'L' && !clockwise) {
                for(int i = 0; i < 3; i++) {
                    temp = cube[0][i][0];
                    cube[0][i][0] = cube[3][i][0];
                    cube[3][i][0] = cube[1][i][0];
                    cube[1][i][0] = cube[5][2-i][2];
                    cube[5][2-i][2] = temp;
                }
                for(int i = 0; i < 2; i++) {
                    temp = cube[2][0][i];
                    cube[2][0][i] = cube[2][i][2];
                    cube[2][i][2] = cube[2][2][2-i];
                    cube[2][2][2-i] = cube[2][2-i][0];
                    cube[2][2-i][0] = temp;
                }
            }
            
            // R+
            if(command[0] == 'R' && clockwise) {
                for(int i = 0; i < 3; i++) {
                    temp = cube[0][i][2];
                    cube[0][i][2] = cube[3][i][2];
                    cube[3][i][2] = cube[1][i][2];
                    cube[1][i][2] = cube[5][2-i][0];
                    cube[5][2-i][0] = temp;
                }
                for(int i = 0; i < 2; i++) {
                    temp = cube[4][i][2];
                    cube[4][i][2] = cube[4][0][i];
                    cube[4][0][i] = cube[4][2-i][0];
                    cube[4][2-i][0] = cube[4][2][2-i];
                    cube[4][2][2-i] = temp;
                }
            }
            
            // R-
            else if(command[0] == 'R' && !clockwise) {
                for(int i = 0; i < 3; i++) {
                    temp = cube[0][i][2];
                    cube[0][i][2] = cube[5][2-i][0];
                    cube[5][2-i][0] = cube[1][i][2];
                    cube[1][i][2] = cube[3][i][2];
                    cube[3][i][2] = temp;
                }
                for(int i = 0; i < 2; i++) {
                    temp = cube[4][0][i];
                    cube[4][0][i] = cube[4][i][2];
                    cube[4][i][2] = cube[4][2][2-i];
                    cube[4][2][2-i] = cube[4][2-i][0];
                    cube[4][2-i][0] = temp;
                }
            }
        }
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++)
                cout << cube[0][i][j];
            cout << '\n';
        }
    }
    
    return 0;
}