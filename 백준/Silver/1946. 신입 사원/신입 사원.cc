#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> arr(N);

        for(int i = 0; i < N; ++i)
            cin >> arr[i].first >> arr[i].second;
        sort(arr.begin(), arr.end());

        int res = 0;
        int lastA = 1e9, lastB = 1e9;
        for(int i = 0; i < N; ++i) {
            int a = arr[i].first, b = arr[i].second;
            if(a <= lastA || b <= lastB) {
                ++res;
                lastA = a;
                lastB = b;
            }
        }
        cout << res << '\n';
    }
    return 0;
}