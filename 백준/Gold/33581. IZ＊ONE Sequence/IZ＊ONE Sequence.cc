#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    
    if(N == K) {
        for(int i = 0; i < N; i++) {
            cout << N-i;
            if(i < N-1) cout << ' ';
        }
    }
    else if(K == N-1) {
        if(N < 5) cout << -1 << '\n';
        else {
            cout << 1 << ' ';
            for(int i = 1; i < N-1; i++)
                cout << N-i << ' ';
            cout << N << '\n';
        }
    }
    else {
        cout << K << ' ';
        for(int i = 1; i <= N; i++) {
            if(i == K || i == K+2) continue;
            cout << i << ' ';
        }
        cout << K+2 << '\n';
    }

    return 0;
}