#include <iostream>
using namespace std;
 
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int point, score = 0;
    for(int i = 0; i < 10; i++) {
        cin >> point;
        if(score+point <= 100) score += point;
        else if(score+point-100 <= 100-score) score += point;
        else break;
    }
    
    cout << score << '\n';
    return 0;
}