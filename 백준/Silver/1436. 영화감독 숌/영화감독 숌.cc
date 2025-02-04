#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isContainsEndNumber(string str, string target) {
        return str.find(target) != string::npos;
    }

int main() {
    int N;
    vector<string> movieTitle;
    int num = 666;
    string endNumber = "666";
    
    cin >> N;

    while (movieTitle.size() < N) {
        string numStr = to_string(num);
        
        if (isContainsEndNumber(numStr, endNumber)) {
            movieTitle.push_back(numStr);  
        }
        
        num++;
    }
    
    cout << movieTitle[N-1];
    return 0;
}