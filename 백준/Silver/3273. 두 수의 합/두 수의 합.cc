#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> *(arr + i);

    int x;
    cin >> x;

    sort(arr, arr + n);

    int* left = arr;
    int* right = arr + n - 1;
    int answer = 0;

    while(left < right) {
        int temp = *left + *right;
        if(temp < x) left++;
        else if(temp > x) right--;
        else {
            answer++;
            left++;
            right--;
        }
    }

    cout << answer << '\n';
    return 0;
}