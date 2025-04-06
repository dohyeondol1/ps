#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> ABC(3);
    for(auto& arr : ABC)
        cin >> arr;
    
    sort(ABC.begin(), ABC.end());
    cout << ABC[1];
    
    return 0;
}