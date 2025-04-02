#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    long long B;
    int N, M;
    cin >> B >> N >> M;
    
    unordered_map<string, long long> itemPrices;
    
    for(int i = 0; i < N; ++i) {
        string itemName;
        long long price;
        cin >> itemName >> price;
        itemPrices[itemName] = price;
    }
    
    long long totalCost = 0;
    for(int i = 0; i < M; ++i) {
        string itemName;
        cin >> itemName;
        totalCost += itemPrices[itemName];
    }
    
    if(totalCost <= B) {
        cout << "acceptable";
    } else {
        cout << "unacceptable";
    }
    
    return 0;
}