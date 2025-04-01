#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    int count = 0, set = N/M;
    count += N;
    count += set;
    while(set >= M){
        set /= M;
        count += set;
    } 
    
    cout << count << '\n';
    return 0;
}