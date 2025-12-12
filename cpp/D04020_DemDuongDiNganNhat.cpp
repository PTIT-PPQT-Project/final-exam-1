#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> ke(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        ke[u].push_back({v, c});
        ke[v].push_back({u, c});
    }

    vector<long long> dist(N + 1, INF);
    vector<long long> count(N + 1, 0);

    priority_queue<pair<long long, int>, 
                   vector<pair<long long, int>>, 
                   greater<pair<long long, int>>> pq;

    int startNode = 1;
    dist[startNode] = 0;
    count[startNode] = 1;
    pq.push({0, startNode});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto& canh : ke[u]) {
            int v = canh.first;
            int w = canh.second;
            long long newDist = d + w;

            if (newDist < dist[v]) {
                dist[v] = newDist;
                count[v] = count[u];
                pq.push({newDist, v});
            } else if (newDist == dist[v]) {
                count[v] += count[u];
            }
        }
    }

    cout << dist[N] << " " << count[N] << "\n";

    return 0;
}
