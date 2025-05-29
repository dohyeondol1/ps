#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    string str1, str2;
    cin >> str1 >> str2;

    for(auto &s1 : str1)
        if(s1 == '6') s1 = '5';
    for(auto &s2 : str2)
        if(s2 == '6') s2 = '5';
    
    cout << stoi(str1) + stoi(str2) << ' ';

    for(auto &s1 : str1)
        if(s1 == '5') s1 = '6';
    for(auto &s2 : str2)
        if(s2 == '5') s2 = '6';
    
    cout << stoi(str1) + stoi(str2) << '\n';
    return 0;
}