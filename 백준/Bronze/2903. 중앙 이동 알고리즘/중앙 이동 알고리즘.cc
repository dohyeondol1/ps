#include <iostream>
using namespace std;
 
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int dot = 2;
    int n;
    cin >> n;
    while(n--) 
        dot = dot*2 - 1;
    
    cout << dot*dot;
    return 0;
}