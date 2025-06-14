#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    string input;
    cin >> input;
 
    int startNumber = 0;
    for(int i = 0; i < 3; i++) {
        startNumber = startNumber*10 + input[i]-'0';
        
        string temp;
        for(int nextNumber = startNumber; ; nextNumber++) {
            temp += to_string(nextNumber);
 
            if(temp == input) {
                cout << startNumber << " " << nextNumber;
                return 0;
            }
            
            if(temp.size() > input.size()) break;
        }
    }

    return 0;
}