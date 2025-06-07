#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dims[11], delta[] = {1, -1};

int main() {
    for(int i = 0; i < 11; i++) 
        cin >> dims[i];

    int a[dims[0]][dims[1]][dims[2]][dims[3]][dims[4]][dims[5]][dims[6]][dims[7]][dims[8]][dims[9]][dims[10]];
    int dist[dims[0]][dims[1]][dims[2]][dims[3]][dims[4]][dims[5]][dims[6]][dims[7]][dims[8]][dims[9]][dims[10]];
    queue<vector<int>> que;

    for(int p = 0; p < dims[10]; p++)
        for(int q = 0; q < dims[9]; q++)
            for(int r = 0; r < dims[8]; r++)
                for(int s = 0; s < dims[7]; s++)
                    for(int t = 0; t < dims[6]; t++)
                        for(int u = 0; u < dims[5]; u++)
                            for(int v = 0; v < dims[4]; v++)
                                for(int w = 0; w < dims[3]; w++)
                                    for(int x = 0; x < dims[2]; x++)
                                        for(int y = 0; y < dims[1]; y++)
                                            for(int z = 0; z < dims[0]; z++) {
                                                cin >> a[z][y][x][w][v][u][t][s][r][q][p];
                                                if(a[z][y][x][w][v][u][t][s][r][q][p] == 1) {
                                                    dist[z][y][x][w][v][u][t][s][r][q][p] = 0;
                                                    que.push({z, y, x, w, v, u, t, s, r, q, p});
                                                }
                                            }

    int ans = 0;
    while (!que.empty()) {
        auto now = que.front(); que.pop();
        int cost = dist[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]][now[9]][now[10]];
        ans = max(ans, cost);
        for(int dim = 0; dim < 11; dim++) {
            for(int k = 0; k < 2; k++) {
                now[dim] += delta[k];
                if(0 <= now[dim] && now[dim] < dims[dim]) {
                    if(a[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]][now[9]][now[10]] == 0) {
                        que.push(now);
                        a[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]][now[9]][now[10]] = 1;
                        dist[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]][now[9]][now[10]] = cost + 1;
                    }
                }
                now[dim] -= delta[k];
            }
        }
    }

    for(int p = 0; p < dims[10]; p++)
        for(int q = 0; q < dims[9]; q++)
            for(int r = 0; r < dims[8]; r++)
                for(int s = 0; s < dims[7]; s++)
                    for(int t = 0; t < dims[6]; t++)
                        for(int u = 0; u < dims[5]; u++)
                            for(int v = 0; v < dims[4]; v++)
                                for(int w = 0; w < dims[3]; w++)
                                    for(int x = 0; x < dims[2]; x++)
                                        for(int y = 0; y < dims[1]; y++)
                                            for(int z = 0; z < dims[0]; z++) {
                                                if(a[z][y][x][w][v][u][t][s][r][q][p] == 0) {
                                                    cout << -1 << '\n';
                                                    return 0;
                                                }
                                            }

    cout << ans << '\n';
    return 0;
}