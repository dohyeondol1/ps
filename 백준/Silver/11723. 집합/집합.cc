#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

    int M;
    cin >> M;
    
    vector<int> arr(21, 0);
    string order;
    int x;
    while(M--) {
        cin >> order;
        if(order == "add") {
            cin >> x;
            arr[x] = 1;
        }
        if(order == "remove") {
            cin >> x;
            arr[x] = 0;
        }
        if(order == "check") {
            cin >> x;
            if(arr[x]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        if(order == "toggle") {
            cin >> x;
            if(arr[x]) arr[x] = 0;
            else arr[x] = 1;
        }
        if(order == "all") {
            for(int i = 1; i < 21; i++)
                arr[i] = 1;
        }
        if(order == "empty") {
            for(int i = 1; i < 21; i++)
                arr[i] = 0;
        }
    }
    
	return 0;
}