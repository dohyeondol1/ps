#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int K;
    cin >> K;

    vector<pair<int, int>> side(6);
    int maxWidth = 0, maxHeight = 0;
    int maxWidthIdx = -1, maxHeightIdx = -1;

    for(int i = 0; i < 6; i++) {
        int dir, len;
        cin >> dir >> len;
        side[i] = {dir, len};
        if((dir == 1 || dir == 2) && len > maxWidth) {
            maxWidth = len;
            maxWidthIdx = i;
        }
        if((dir == 3 || dir == 4) && len > maxHeight) {
            maxHeight = len;
            maxHeightIdx = i;
        }
    }

    int prevIdx = (maxWidthIdx+5) % 6;
    int nextIdx = (maxWidthIdx+1) % 6;
    int smallHeight = abs(side[prevIdx].second - side[nextIdx].second);

    prevIdx = (maxHeightIdx + 5) % 6;
    nextIdx = (maxHeightIdx + 1) % 6;
    int smallWidth = abs(side[prevIdx].second - side[nextIdx].second);

    int area = (maxWidth * maxHeight) - (smallWidth * smallHeight);
    cout << area*K << '\n';

    return 0;
}