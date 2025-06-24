#include <iostream>
using namespace std;

const int MAX = 500001;

int N, M;
int budae[MAX];
int tree[4*MAX];

void init(int node, int start, int end) {
    if(start == end) {
        tree[node] = budae[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int start, int end, int idx, int diff) {
    if(idx < start || idx > end) return;
    tree[node] += diff;
    
    if(start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

int find(int node, int start, int end, int k) {
    if(start == end) return start;
    int mid = (start + end) / 2;
    if(tree[node * 2] >= k)
        return find(node * 2, start, mid, k);
    else
        return find(node * 2 + 1, mid + 1, end, k - tree[node * 2]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> budae[i];
    
    init(1, 1, N);
    
    cin >> M;
    while(M--) {
        int query, i, a;
        cin >> query >> i;
        if(query == 1) {
            cin >> a;
            update(1, 1, N, i, a);
        }
        else
            cout << find(1, 1, N, i) << '\n';
    }
        
    return 0;
}