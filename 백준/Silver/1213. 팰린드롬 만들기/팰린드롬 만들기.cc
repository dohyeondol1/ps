#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cnt[26];
char mid;
string leftt, rightt;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string imhansoo;
    cin >> imhansoo;
    for(char c : imhansoo)
        cnt[c-'A']++;

    int odd = 0;
    for(int i = 0; i < 26; ++i) {
        if(cnt[i] % 2) {
            odd++;
            mid = i + 'A';
        }
    }

    if(odd > 1) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    for(int i = 0; i < 26; ++i)
        for(int j = 0; j < cnt[i]/2; ++j)
            leftt += i + 'A';
    
    rightt = leftt;
    reverse(rightt.begin(), rightt.end());

    if(mid)
        cout << leftt << mid << rightt << '\n';
    else
        cout << leftt << rightt << '\n';
    
    return 0;
}