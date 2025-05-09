#include <iostream>
using namespace std;

int main() {
    int n, answer;
    while(1) {
        answer = 0;
        cin >> n;
        if(n == 0) break;
        for(int i = 1; i <= n; i++)
            answer += i;
        cout << answer << '\n';
    }
    return 0;
}