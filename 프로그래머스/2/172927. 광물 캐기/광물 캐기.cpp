#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 곡괭이에 따라 피로도 계산
int getFatigue(string pick, string mineral) {
    if(pick == "dia") return 1;
    if(pick == "iron") {
        if(mineral == "diamond") return 5;
        else return 1;
    }
    if(pick == "stone") {
        if(mineral == "diamond") return 25;
        else if(mineral == "iron") return 5;
        else return 1;
    }
    return 0;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;

    int totalPicks = picks[0] + picks[1] + picks[2];
    int maxMine = min((int)minerals.size(), totalPicks * 5);
    
    // 광물 5개씩 자르기
    vector<vector<string>> mineralGroups;
    for(int i = 0; i < maxMine; i += 5) {
        vector<string> group;
        for(int j = i; j < i + 5 && j < maxMine; ++j) {
            group.push_back(minerals[j]);
        }
        mineralGroups.push_back(group);
    }

    // 피로도 계산
    vector<pair<int, int>> fatigueIndex;
    for(int i = 0; i < mineralGroups.size(); ++i) {
        int fatigue = 0;
        for(const string& m : mineralGroups[i]) {
            fatigue += getFatigue("stone", m);
        }
        fatigueIndex.push_back({fatigue, i});
    }

    // 피로도 높은 순으로 그룹 정렬
    sort(fatigueIndex.rbegin(), fatigueIndex.rend());

    // 곡괭이 순서대로 그룹에 배정 (좋은 곡괭이는 힘든 그룹에)
    for(pair<int, int> p : fatigueIndex) {
        int index = p.second;
        
        if(picks[0] > 0) {
            for(const string& m : mineralGroups[index]) {
                answer += getFatigue("dia", m);
            }
            picks[0]--;
        } else if(picks[1] > 0) {
            for(const string& m : mineralGroups[index]) {
                answer += getFatigue("iron", m);
            }
            picks[1]--;
        } else if(picks[2] > 0) {
            for(const string& m : mineralGroups[index]) {
                answer += getFatigue("stone", m);
            }
            picks[2]--;
        } else {
            break;
        }
    }

    return answer;
}