#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binary_search(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    vector<int> N_array(N);
    for (int i = 0; i < N; i++) {
        cin >> N_array[i];
    }
    
    sort(N_array.begin(), N_array.end());

    int M, target;
    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> target;
        cout << binary_search(N_array, target);
        if (i != M - 1) cout << " ";
    }

    return 0;
}