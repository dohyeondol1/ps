#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer(commands.size());
    
    for(int i = 0; i < commands.size(); i++) {
        vector<int> cuttingArray;
        for(int j = commands[i][0]; j <= commands[i][1]; j++) {
            cuttingArray.push_back(array[j-1]);
        }
        
        sort(cuttingArray.begin(), cuttingArray.end());
        answer[i] = cuttingArray[commands[i][2]-1];
    }
    
    return answer;
}