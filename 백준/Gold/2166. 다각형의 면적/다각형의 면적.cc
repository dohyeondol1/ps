#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;
    
    vector<pair<double, double>> c(N);
    for(int i = 0; i < N; i++)
        cin >> c[i].first >> c[i].second;

    double S = 0;
    for(int i = 0; i < N; i++) {
        int j = (i+1)%N;
        S += c[i].first * c[j].second - c[j].first * c[i].second;
    }
        
    cout << fixed << setprecision(1) << abs(S) / 2.0 << '\n';
    return 0;
}