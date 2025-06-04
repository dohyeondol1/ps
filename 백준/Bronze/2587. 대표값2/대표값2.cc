#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int score[5];
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        cin >> score[i];
        sum += score[i];
    }
    
    sort(score, score+5);
    cout << sum/5 << '\n' << score[2] << '\n';
    return 0;
}