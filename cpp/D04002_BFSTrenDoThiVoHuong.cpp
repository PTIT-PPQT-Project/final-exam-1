#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int start_node, int num_vertices, vector<vector<int>>& adj) {
    queue<int> q;
    vector<bool> visited(num_vertices + 1, false);

    q.push(start_node);
    visited[start_node] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void giaiQuyet() {
    int V, E, start_node;
    
    if (!(cin >> V >> E >> start_node)) return;

    vector<vector<int>> adj(V + 1);

    for (int i = 0; i < E; ++i) {
        int u, v;
        if (!(cin >> u >> v)) return;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= V; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    bfs(start_node, V, adj);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        giaiQuyet();
    }

    return 0;
}
