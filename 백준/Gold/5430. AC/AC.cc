#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) {
        string order;
        int N;
        cin >> order >> N;

        deque<int> dq;
        char ch;
        cin >> ch;
        for(int i = 0; i < N; i++) {
            int x;
            cin >> x;
            dq.push_back(x);
            if(i != N - 1) cin >> ch;
        }
        cin >> ch;

        bool isReverse = false, isError = false;
        for(char c : order) {
            if(c == 'R') {
                isReverse = !isReverse;
            } else if(c == 'D') {
                if(dq.empty()) {
                    isError = true;
                    break;
                }
                if(!isReverse) dq.pop_front();
                else dq.pop_back();
            }
        }

        if(isError) {
            cout << "error" << '\n';
        } else {
            cout << '[';
            if(!dq.empty()) {
                if(!isReverse) {
                    for(size_t i = 0; i < dq.size(); i++) {
                        cout << dq[i];
                        if(i != dq.size() - 1) cout << ',';
                    }
                } else {
                    for(size_t i = dq.size(); i-- > 0;) {
                        cout << dq[i];
                        if(i != 0) cout << ',';
                    }
                }
            }
            cout << "]" << '\n';
        }
    }

    return 0;
}