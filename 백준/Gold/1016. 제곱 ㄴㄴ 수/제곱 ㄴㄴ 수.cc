#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool check[1000001] = { 0, };

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    long long min, max, temp, cnt = 0;
    cin >> min >> max;
    
    for(long long i = 2; i*i <= max; i++) {
        temp = min/(i*i);
        if(min%(i*i)) temp++;
        while(temp*i*i <= max) {
            check[temp*i*i - min] = 1;
            temp++;
        }
    }
    
    for(int i = 0; i <= max-min; i++) 
        if(!check[i]) cnt++;
    
    cout << cnt << '\n'; 
    return 0;
}