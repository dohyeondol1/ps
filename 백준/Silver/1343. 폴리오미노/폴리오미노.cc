#include <iostream>
#include <string>
using namespace std;

int main() {
    string board;
    cin >> board;

    //board에 XXXX가 있을때 동안만
    while(board.find("XXXX") != string::npos) {
        int pos = board.find("XXXX");
        board.replace(pos, 4, "AAAA");
    }

    while(board.find("XX") != string::npos) {
        int pos = board.find("XX");
        board.replace(pos, 2, "BB");
    }

    if(board.find('X') != string::npos) cout << -1 << '\n';
    else cout << board << '\n';

    return 0;
}