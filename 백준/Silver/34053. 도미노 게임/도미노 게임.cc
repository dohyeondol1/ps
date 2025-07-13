#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
long long num, sum = 0, minValue = 1e9 + 1;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> num;
            if(num < minValue) minValue = num;
            sum += num;
        }
    }
    
    long long answer = sum - minValue;
    cout << answer << '\n';
    return 0;
}