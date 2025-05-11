#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp {
	bool operator()(int a, int b){
        if(abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    priority_queue<int, vector<int>, cmp> pq;
    for(int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        if(x == 0) {
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
    
    return 0;
}