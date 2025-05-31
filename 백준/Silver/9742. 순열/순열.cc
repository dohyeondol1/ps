#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string permutation;
    int pos;
    while(cin >> permutation >> pos) {
        string str = permutation;
        int count = 1;
        sort(str.begin(), str.end());
        while(next_permutation(str.begin(), str.end())) {
            count++;
            if(count == pos) break;
        }
        if(count == pos) cout << permutation << ' ' << pos << " = " << str << '\n';
        else cout << permutation << ' ' << pos << " = " << "No permutation" << '\n';
    }
    
    return 0;
}