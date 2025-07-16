#include <iostream>
using namespace std;

int main() {
    int T, H, W, N;
    cin >> T;
    while(T--){
        cin >> H >> W >> N;
        int num = N/H+1;
        int flr = N%H;
        if(flr == 0)    
            num--, flr = H;
        int room = (flr*100)+num;
        
        cout << room << '\n';
    }
    
    return 0;
}