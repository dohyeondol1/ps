#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
 
    int X;
    cin >> X;
    int line = 1;
    while(X > line) {
        X -= line;
        line++;
    }

    if(line%2 == 0) cout << X << '/' << line-X+1;
    else cout << line-X+1 << '/' << X;
    
    return 0;
}