#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string word;
    cin >> word;
    int now = 0, times = 0;
    for(int i = 0; i< word.length(); i++){
        int next = word[i]-'A';
        int distance1 = abs(now-next);
        int distance2 = 26-distance1;
        if(distance1 < distance2) times += distance1;
        else times += distance2;
        now = next;
    }
    cout << times << '\n';
    
    return 0;
}