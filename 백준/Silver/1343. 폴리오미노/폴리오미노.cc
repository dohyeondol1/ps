#include <iostream>
#include <string>
using namespace std;

int main() {
    string board;
    cin >> board;

    //board에 XXXX가 있을때 동안만
    while(board.find("XXXX") != string::npos)
        board.replace(board.find("XXXX"), 4, "AAAA");

    while(board.find("XX") != string::npos)
        board.replace(board.find("XX"), 2, "BB");

    if(board.find('X') != string::npos) cout << -1;
    else cout << board;

    return 0;
}