#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    pair<int, int> answer;
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    for(int i = -999; i <= 999; i++)
        for(int j = -999; j <= 999; j++)
            if(a*i + b*j == c && d*i + e*j == f) {
                answer = {i, j};
                break;
            }
    
    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}