#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, opinion, count = 0;
    cin >> N;
    while(N--) {
        cin >> opinion;
        if(opinion == 1) count++;
        else count--;
    }
    
    if(count > 0) cout << "Junhee is cute!";
    else cout << "Junhee is not cute!";

    return 0;
}