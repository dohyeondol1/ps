#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
	cin >> N >> M;
	if (N*M == 2) cout << "ChongChong";
	else cout << "GomGom";
    
    return 0;
}