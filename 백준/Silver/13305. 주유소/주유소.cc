#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int cityCount, answer = 0;
    cin >> cityCount;
    
    vector<int> distance(cityCount);
    for(int i = 0; i < cityCount-1; i++)
        cin >> distance[i];
    
    vector<int> cost(cityCount);
    for(int i = 0; i < cityCount; i++)
        cin >> cost[i];
        
    int minCost = 0;
    for(int i = 0; i < cityCount-1; i++) {
        if(i == 0) minCost = cost[i];
        else minCost = min(cost[i], minCost);
        
        answer += minCost*distance[i];
    }
    
    cout << answer << '\n';
    return 0;
}