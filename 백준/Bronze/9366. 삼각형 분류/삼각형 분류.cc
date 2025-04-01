#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    int A, B, C;
    for(int i = 1; i <= T; i++) {
        int arr[3];
        for(int j = 0; j < 3; j++) cin >> arr[j];
        sort(arr, arr+3);
        cout << "Case #" << i << ": ";
        if(arr[0]+arr[1] <= arr[2]) cout << "invalid!" << '\n';
        else if(arr[0] == arr[1] && arr[0] == arr[2]) cout << "equilateral" << '\n';
        else if(arr[0] == arr[1] || arr[1] == arr[2]) cout << "isosceles" << '\n';
        else cout << "scalene" << '\n';
    }
    
    return 0;
}