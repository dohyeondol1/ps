#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M; 
    cin >> N >> M;
    vector<string> answer;
    unordered_map<string, int> umap;
    
    string unheard = "";
    for(int i = 0; i < N; i++) {
        cin >> unheard;
        umap[unheard] = 0;
    }
    
    string unseen = "";
    for(int i = 0; i < M; i++) {
        cin >> unseen;
        if(umap.find(unseen) != umap.end()) answer.push_back(unseen);
    }
    
    sort(answer.begin(), answer.end());
    
    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << "\n";
    
    return 0;
}