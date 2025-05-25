#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    long long answer = 0;
    
    int cityCount;
    cin >> cityCount;
    
    vector<long long> distance(cityCount);
    for(int i = 0; i < cityCount-1; i++)
        cin >> distance[i];
    
    vector<long long> cost(cityCount);
    for(int i = 0; i < cityCount; i++)
        cin >> cost[i];
        
    long long minCost = 0;
    for(int i = 0; i < cityCount-1; i++) {
        if(i == 0) minCost = cost[i];
        else minCost = min(cost[i], minCost);
        
        answer += minCost*distance[i];
    }
    
    cout << answer << '\n';
    return 0;
}