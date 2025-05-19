#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i = N*2-1; i > 0; i-=2) {
        for(int j = (N*2-1 - i)/2; j > 0; j--)
            cout << ' ';
        for(int j = i; j > 0; j--)
            cout << '*';
        cout << '\n';
    }
    for(int i = 3; i <= N*2-1; i+=2) {
        for(int j = (N*2-1 - i)/2; j > 0; j--)
            cout << ' ';
        for(int j = i; j > 0; j--)
            cout << '*';
        cout << '\n';
    }

    return 0;
}