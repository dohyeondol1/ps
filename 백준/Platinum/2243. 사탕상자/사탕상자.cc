#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
int tree[4*MAX+1];

void update(int node, int start, int end, int idx, int diff) {
    if(idx < start || idx > end) return;
    tree[node] += diff;
    
    if(start != end) {
        int mid = (start + end)/2;
        update(node*2, start, mid, idx, diff);
        update(node*2+1, mid+1, end, idx, diff);
    }
}

int query(int node, int start, int end, int k) {
    if(start == end) return start;
    int mid = (start + end)/2;
    if(tree[node * 2] >= k)
        return query(node*2, start, mid, k);
    else
        return query(node*2+1, mid+1, end, k - tree[node*2]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    while(n--) {
        int op;
        cin >> op;
        if(op == 1) {
            int k;
            cin >> k;
            int flavor = query(1, 1, MAX, k);
            cout << flavor << '\n';
            update(1, 1, MAX, flavor, -1);
        } 
        else if(op == 2) {
            int b, c;
            cin >> b >> c;
            update(1, 1, MAX, b, c);
        }
    }
    
    return 0;
}