#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int N_array[1000000];

void binary_search(int x) {
    int left = 0, mid = 0, right = N - 1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (N_array[mid] == x) {
            cout << 1 << '\n';
            return;
        } else if (N_array[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << 0 << "\n";

    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> N_array[i];

    sort(N_array, N_array + N);
    
    cin >> M; int x;
    for (int i = 0; i < M; i++) {
        cin >> x;
        binary_search(x);
    }

    return 0;
}