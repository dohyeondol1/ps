#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    
    string site, password;
    unordered_map<string, string> umap;
    while(N--) {
        cin >> site >> password;
        umap.insert(make_pair(site, password));
    }
    
    string targetSite;
    while(M--) {
        cin >> targetSite;
        cout << umap[targetSite] << '\n';
    }
    
    return 0;
}