#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> p1 = {1, 2, 3, 4, 5};
    vector<int> p2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int count1 = 0, count2 = 0, count3 = 0;

    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == p1[i%p1.size()]) count1++;
        if(answers[i] == p2[i%p2.size()]) count2++;
        if(answers[i] == p3[i%p3.size()]) count3++;
    }
    
    int maxCorrect = max({count1, count2, count3});
    if(maxCorrect == count1) answer.push_back(1);
    if(maxCorrect == count2) answer.push_back(2);
    if(maxCorrect == count3) answer.push_back(3);
    
    return answer;
}