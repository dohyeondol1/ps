#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPi(const string& pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);
    int j = 0;

    for(int i = 1; i < m; ++i) {
        while(j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1];

        if(pattern[i] == pattern[j]) pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp(const string& text, const string& pattern) {
    vector<int> result;
    vector<int> pi = getPi(pattern);
    int n = text.size();
    int m = pattern.size();
    int j = 0;

    for(int i = 0; i < n; ++i) {
        while(j > 0 && text[i] != pattern[j])
            j = pi[j - 1];

        if(text[i] == pattern[j]) {
            if(j == m - 1) {
                result.push_back(i-m+2);
                j = pi[j];
            }
            else
                j++;
        }
    }

    return result;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    string T, P;
    getline(cin, T);
    getline(cin, P);

    vector<int> matched = kmp(T, P);

    cout << matched.size() << '\n';
    for(int pos : matched)
        cout << pos << ' ';
    cout << '\n';

    return 0;
}