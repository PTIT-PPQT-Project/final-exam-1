#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

    for (int i = 1; i <= N; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        cout << dist[u][v] << "\n";
    }

    return 0;
}
