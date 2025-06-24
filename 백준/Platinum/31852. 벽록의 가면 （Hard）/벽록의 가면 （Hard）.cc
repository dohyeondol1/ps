#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = acos(-1);

long long combination(long long n, int k) {
    if(k == 2) return n*(n-1)/2;
    if(k == 3) return n*(n-1)*(n-2)/6;
    if(k == 4) return n*(n-1)*(n-2)*(n-3)/24;
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;
    vector<pair<long long,long long>> pt(N);
    for(int i = 0; i < N; ++i)
        cin >> pt[i].first >> pt[i].second;

    long long total4 = combination(N, 4);
    long long concave = 0;

    for(int i = 0; i < N; ++i) {
        vector<double> angle;
        angle.reserve(N-1);
        for(int j = 0; j < N; ++j) {
            if(j == i) continue;
            long long dx = pt[j].first  - pt[i].first;
            long long dy = pt[j].second - pt[i].second;
            angle.push_back(atan2((double)dy, (double)dx));
        }

        int M = angle.size();
        sort(angle.begin(), angle.end());
        angle.resize(2*M);
        for(int j = 0; j < M; ++j)
            angle[M+j] = angle[j] + 2*PI;

        long long totalTrianglele = combination(M, 3);
        long long nonContain = 0;

        int r = 0;
        for(int l = 0; l < M; ++l) {
            while(r < l+M && angle[r]-angle[l] < PI) r++;
            long long k = r - l - 1;
            if(k >= 2) nonContain += combination(k, 2);
        }

        long long contain = totalTrianglele - nonContain;
        concave += contain;
    }

    long long answer = total4 - concave;
    cout << answer << '\n';
    return 0;
}