#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    double H, W;
    cin >> H >> W;
    if(H <= W) cout << H*0.5*100 << '\n';
    else cout << W*0.5*100 << '\n';
    
    return 0;
}