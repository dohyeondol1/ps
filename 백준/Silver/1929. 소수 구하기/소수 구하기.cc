#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    
    vector<int> arr(N+1, 0);
    for(int i = 2; i <= N; i++)
        arr[i] = i;

    for(int i = 2; i*i <= N; i++) {
        if(arr[i] == 0) continue;
        for(int j = 2*i; j <= N; j += i) {
            if(arr[j] == 0)  continue;
            else arr[j] = 0;
        }
    }

    for(int i = M; i <= N; i++)
        if(arr[i] != 0) cout << arr[i] << '\n';

    return 0;
}