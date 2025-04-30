#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> graph[200001];
bool states[2][200001];
bool vis[2][200001]; //변수명 좀 더 고민해보

//노드, 현재 상태, count, 상태, 방문 여부
bool dfs(int node, bool currentFlag, int& count, bool state[], bool visited[]) {
    visited[node] = true;
    state[node] = currentFlag;  //현재 노드 상태 저장
    if(currentFlag) count++;   //상태가 true면 count 증가

    for(int i = 0; i < graph[node].size(); i++) {
        int nextNode = graph[node][i].first;
        int edgeType = graph[node][i].second;

        //다음 노드
        bool nextFlag;
        if(edgeType == 0) nextFlag = false;
        else if(edgeType == 2) nextFlag = true;
        else nextFlag = !currentFlag;

        //현재 상태와 간선 타입이 충돌하는 경우
        if ((edgeType == 0 && currentFlag) || (edgeType == 2 && !currentFlag)) {
            return false;
        }

        //이미 방문한 경우 상태가 일치하는지 확인
        if(visited[nextNode]) {
            if(state[nextNode] != nextFlag) return false;
        } else {
            if(!dfs(nextNode, nextFlag, count, state, visited)) return false;
        }
    }

    return true;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    int minLounge = 0;

    for(int i = 0; i < n && minLounge >= 0; i++) {
        if(vis[0][i] || vis[1][i]) continue;

        int count0 = 0, count1 = 0;

        if(!vis[0][i]) {
            bool valid0 = dfs(i, false, count0, states[0], vis[0]);
            if (!valid0) count0 = -1;
        }

        if(!vis[1][i]) {
            bool valid1 = dfs(i, true, count1, states[1], vis[1]);
            if (!valid1) count1 = -1;
        }

        if(count0 < 0 && count1 < 0) {
            minLounge = -1;
        } else if(count0 < 0) {
            minLounge += count1;
        } else if(count1 < 0) {
            minLounge += count0;
        } else {
            minLounge += min(count0, count1);
        }
    }

    if(minLounge < 0) cout << "impossible" << '\n';
    else  cout << minLounge << '\n';

    return 0;
}