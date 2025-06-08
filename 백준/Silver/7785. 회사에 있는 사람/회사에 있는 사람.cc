#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    map<string, string, greater<>> m;
    for(int i = 0; i < n; i++) {
        string name, recode;
        cin >> name >> recode;
        m[name] = recode;
    }
    
    map<string, string>::iterator it;
    for(it = m.begin(); it != m.end(); it++)
        if(it->second == "enter") cout << it->first << '\n';
    
    return 0;
}