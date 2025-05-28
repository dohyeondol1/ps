#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> arr(10, 0);
    while(N > 0) {
        arr[N%10]++;
        N /= 10;
    }

    int sixNine = arr[6] + arr[9];
    arr[6] = arr[9] = (sixNine+1) / 2;

    int maxSet = *max_element(arr.begin(), arr.end());
    cout << maxSet << '\n';
    return 0;
}