#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    int gap1 = B-A;
    int gap2 = C-B;
    
    cout << max(gap1, gap2)-1 << '\n';
    return 0;
}