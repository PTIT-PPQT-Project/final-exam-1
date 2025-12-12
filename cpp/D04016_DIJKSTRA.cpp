#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void giaiQuyet() {
    int V, E, u;
    cin >> V >> E >> u;

    vector<vector<pair<int, int>>> ke(V + 1);
    for (int i = 0; i < E; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        ke[a].push_back({b, w});
        ke[b].push_back({a, w});
    }

    vector<int> dist(V + 1, INF);
    dist[u] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, u});

    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d > dist[v]) {
            continue;
        }

        for (auto& canh : ke[v]) {
            int hangXom = canh.first;
            int trongSo = canh.second;

            if (dist[v] + trongSo < dist[hangXom]) {
                dist[hangXom] = dist[v] + trongSo;
                pq.push({dist[hangXom], hangXom});
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        giaiQuyet();
    }
    return 0;
}
