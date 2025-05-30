#include <iostream>
using namespace std;

int main() {
    int payment;
    cin >> payment;
    
    int count = 0;
    int change = 1000 - payment;
    if(change >= 500) {
        count += change/500;
        change %= 500;
    }
    if(change >= 100) {
        count += change/100;
        change %= 100;
    }
    if(change >= 50) {
        count += change/50;
        change %= 50;
    }
    if(change >= 10) {
        count += change/10;
        change %= 10;
    }
    if(change >= 5) {
        count += change/5;
        change %= 5;
    }
    if(change > 0) count += change;

    cout << count << '\n';
    return 0;
}