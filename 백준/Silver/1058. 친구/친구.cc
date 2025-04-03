#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> isfriends(N);
    for(int i = 0; i < N; i++)
        cin >> isfriends[i];

    vector<int> friends2Count(N, 0);

    for(int i = 0; i < N; i++) {
        set<int> friends2;

        for(int j = 0; j < N; j++) {
            if(isfriends[i][j] == 'Y') {
                friends2.insert(j);
                for(int k = 0; k < N; k++) {
                    //자신(i)이 아니면서 i의 친구(j)의 친구(k) 추가
                    if(isfriends[j][k] == 'Y' && k != i) {
                        friends2.insert(k);
                    }
                }
            }
        }

        friends2Count[i] = friends2.size();
    }

    int maxFriends2Count = 0;
    for(int count : friends2Count) {
        maxFriends2Count = max(maxFriends2Count, count);
    }

    cout << maxFriends2Count << '\n';

    return 0;
}