#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> dice(6);
    for(auto& d : dice) 
        cin >> d;

    if(N == 1) {
        int sum = 0;
        for(int i = 0; i < 6; i++) sum += dice[i];
        int maxFace = *max_element(dice.begin(), dice.end());
        cout << sum - maxFace << '\n';
        return 0;
    }

    int oneMin = *min_element(dice.begin(), dice.end());

    int twoMin = 1e9;
    for(int i = 0; i < 6; i++) {
        for(int j = i+1; j < 6; j++) {
            if(i+j == 5) continue;
            twoMin = min(twoMin, dice[i] + dice[j]);
        }
    }

    int threeMin = 1e9;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(i == j || i+j == 5) continue;
            for(int k = 0; k < 6; k++) {
                if(k == i || k == j || i+k == 5 || j+k == 5) continue;
                threeMin = min(threeMin, dice[i] + dice[j] + dice[k]);
            }
        }
    }

    long long threeCount = 4;
    long long twoCount = 8*N - 12;
    long long oneCount = 5LL*N*N - 16*N + 12;

    long long answer = 0;
    answer += threeCount * threeMin;
    answer += twoCount * twoMin;
    answer += oneCount * oneMin;

    cout << answer << '\n';
    return 0;
}