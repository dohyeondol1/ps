#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> multiMat(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            long long sum = 0;
            for(int k = 0; k < n; ++k)
                sum += 1LL * A[i][k] * B[k][j];
            C[i][j] = sum % 1000;
        }
    return C;
}

vector<vector<int>> powerMatrix(vector<vector<int>> A, long long power) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) result[i][i] = 1;

    vector<vector<int>> base = A;
    while(power > 0) {
        if(power % 2 == 1)
            result = multiMat(result, base);
        base = multiMat(base, base);
        power /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long b;
    cin >> n >> b;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(auto& row : matrix) {
        for(int& x : row) {
            cin >> x;
            x %= 1000;
        }
    }

    auto answer = powerMatrix(matrix, b);

    for(auto& row : answer) {
        for(int j = 0; j < n; ++j) {
            cout << row[j];
            if(j + 1 != n) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}