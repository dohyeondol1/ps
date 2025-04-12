#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, L;
    cin >> N >> L;
    
    vector<int> x(N);
    for(int &position : x)
        cin >> position;
    
    vector<int> w(N);
    for(int &weight : w)
        cin >> weight;
    
    double totalW = accumulate(w.begin(), w.end(), 0.0);
    double totalXTimesW = 0.0;
    for(int i = 0; i < N; i++)
        totalXTimesW += static_cast<double>(x[i]) * w[i];
    
    double result = totalXTimesW / totalW;
    
    cout << fixed << setprecision(10) << result << '\n';
    
    return 0;
}