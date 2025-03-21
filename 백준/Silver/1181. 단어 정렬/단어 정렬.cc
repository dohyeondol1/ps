#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compareLength(string a, string b) {
    
    if(a.length() == b.length()) return a < b;
    else return a.length() < b.length();
}

int main() {
    int N;
    cin >> N;
    
    vector<string> word(N);
    for(string &Word : word) {
        cin >> Word;
    }

    sort(word.begin(), word.end(), compareLength);
    word.erase(unique(word.begin(), word.end()), word.end());
    
    for(string &Word : word) {
        cout << Word << '\n';
    }
    
    return 0;
}