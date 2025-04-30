#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    answer += n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (int i = 0; i < lost.size(); ) {
        bool found = false;
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                found = true;
                answer++;
                break;
            }
        }
        if (!found) i++;
    }
    
    for(int i = 0; i < lost.size(); i++) {
        for(int j = 0; j < reserve.size(); j++) {
            if((lost[i]-1) == reserve[j]) {
                reserve.erase(reserve.begin());
                answer++;
                break;
            }
            else if(lost[i]+1 == reserve[j]) {
                reserve.erase(reserve.begin());
                answer++;
                break;
            }
        }
    }
    
    return answer;
}

// 1. 벡터를 한개씩 더 만들어서 사용한다
// 2. '빌렸음' // '빌려 줄 수 있음' 여부 bool값으로 사용한다.