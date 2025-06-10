#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Z(int n, int r, int c) {
    int result = 0;
    int size = 1;
    for(int i = 0; i < n; i++)
        size *= 2;

    while(n > 0) {
        n--;
        size /= 2;

        if(r < size && c < size) 
            result += 0;
        else if(r < size && c >= size) {
            result += size*size;
            c -= size;
        }
        else if(r >= size && c < size) {
            result += 2*size*size;
            r -= size;
        }
        else {
            result += 3*size*size;
            r -= size;
            c -= size;
        }
    }
    
    return result;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, r, c;
    cin >> N >> r >> c;
    cout << Z(N, r, c) << '\n';
    return 0;
}