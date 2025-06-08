// multiset을 이용한 풀이. 참고할 것
#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) {
        int k;
        cin >> k;

        multiset<int> s;
        for(int i = 0; i < k; i++) {
            char cmd;
            int n;
            cin >> cmd >> n;

            if(cmd == 'I') {
                s.insert(n);
                continue;
            }

            if(s.empty()) continue;

            if(n == -1) s.erase(s.begin());
            else s.erase(prev(s.end()));
        }

        if(s.empty()) cout << "EMPTY" << '\n';
        else cout << *s.rbegin() << ' ' << *s.begin() << '\n';
    }
}