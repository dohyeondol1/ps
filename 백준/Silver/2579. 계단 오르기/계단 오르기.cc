#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int stepCount;
    cin >> stepCount;

    vector<int> stepScores(stepCount+1);
    for(int i = 1; i <= stepCount; i++) {
        cin >> stepScores[i];
    }
    
    vector<int> Score(stepCount+1);
    Score[1] = stepScores[1];
    Score[2] = stepScores[1]+stepScores[2];
    Score[3] = max(stepScores[2]+stepScores[3], stepScores[1]+stepScores[3]);
    for(int i = 4; i <= stepCount; i++) {
        Score[i] = max(Score[i-3]+stepScores[i-1]+stepScores[i], Score[i-2]+stepScores[i]);
    }
    
    cout << Score[stepCount] << '\n';
    
    return 0;
}