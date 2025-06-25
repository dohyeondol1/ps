#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;
    vector<int> answers(T);
    for(int i = 0; i < T; ++i) {
        int target;
        cin >> target;

        if(target < 3) {
            answers[i] = target;
            continue;
        }

        int curr = 4, prev = 2, height = 3;
        int next = curr + prev + 1;
        while(next <= target) {
            prev = curr;
            curr = next;
            height++;
            next = curr + prev + 1;
        }
        answers[i] = height;
    }

    for(int i = 0; i < T; ++i)
        cout << answers[i] << '\n';

    return 0;
}