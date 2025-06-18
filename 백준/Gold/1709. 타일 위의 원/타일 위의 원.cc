#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    long long N;
    cin >> N;
    N /= 2;
    
    long long answer = 0;
    long long x1 = 0, y1 = N;
    for(long long y2 = N-1; y2 >= 0; --y2){
        long long x2 = x1;
        while((x2+1)*(x2+1) + y2*y2 <= N*N) 
            x2 += 1;
        
        if(x2*x2 + y2*y2 == N*N) answer += x2-x1;
        else answer += x2-x1+1;
        
        y1 = y2;
        x1 = x2;
    }
    
    cout << answer * 4 << '\n';
    return 0;
}