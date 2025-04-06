#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, temp;
    cin >> N >> M;
    
    vector<int> psum(100000);
    for(int i = 1; i <= N; i++) {
        cin >> temp;
        psum[i] = psum[i-1] + temp;
    }
    
    vector<int> start(M), end(M);
    for(int i = 0; i < M; i++)
        cin >> start[i] >> end[i];
    
    for(int i = 0; i < M; i++)
        cout << psum[end[i]] - psum[start[i]-1] << '\n';
    
    return 0;
}