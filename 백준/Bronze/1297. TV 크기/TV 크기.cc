#include <iostream>  
#include <cmath>
using namespace std;

int main() {
    int D, H, W;
    cin >> D >> H >> W;
    
    double R = sqrt(W * W + H * H);
    double width = D * W / R;
    double height = D * H / R;
    cout << (int)height << ' ' << (int)width;

    return 0;
}