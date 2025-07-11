#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int L, C;
vector<char> chars;
vector<char> password;

void dfs(int start, int depth) {
    if(depth == L) {
        int vowel = 0, consonant = 0;
        for(char c : password) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowel++;
            else consonant++;
        }

        if(vowel >= 1 && consonant >= 2) {
            for(char c : password)
                cout << c;
            cout << '\n';
        }

        return;
    }

    for(int i = start; i < C; ++i) {
        password.push_back(chars[i]);
        dfs(i+1, depth+1);
        password.pop_back();
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> L >> C;
    chars.resize(C);
    for(int i = 0; i < C; ++i)
        cin >> chars[i];

    sort(chars.begin(), chars.end());
    dfs(0, 0);

    return 0;
}