#include <iostream>
#include <cmath>
using namespace std;

int arr[101][101];
int dx[4]={ -1, 1, 0, 0};
int dy[4]={ 0, 0, -1, 1};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    int sum = 2*N*M;

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> arr[i][j];

    for(int x = 0; x < N; ++x) {
        for(int y = 0; y < M; ++y) {
            for(int i= 0 ; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx > N || ny < 0 || ny > M) sum += arr[x][y];
                else if (arr[x][y] > arr[nx][ny]) sum += (arr[x][y] - arr[nx][ny]); 
            }
        }
    }
   
    cout << sum << '\n';
    return 0;
}