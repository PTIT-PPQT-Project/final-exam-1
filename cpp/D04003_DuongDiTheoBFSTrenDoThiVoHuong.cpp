#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

void printPath(int s, int t, const vector<int>& parent) {
    if (parent[t] == 0) {
        cout << -1 << endl;
        return;
    }

    stack<int> path;
    int current = t;
    
    while (current != 0) {
        path.push(current);
        if (current == s) break;
        current = parent[current];
    }
    
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}

void bfs_path(int s, int t, int num_vertices, vector<vector<int>>& adj) {
    queue<int> q;
    vector<int> parent(num_vertices + 1, 0); 
    
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == t) {
            printPath(s, t, parent);
            return;
        }

        for (int v : adj[u]) {
            if (parent[v] == 0) { 
                parent[v] = u;
                q.push(v);
            }
        }
    }

    cout << -1 << endl;
}

void giaiQuyet() {
    int V, E, s, t;
    
    if (!(cin >> V >> E >> s >> t)) return;

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

    if (s == t) {
        cout << s << endl;
        return;
    }

    bfs_path(s, t, V, adj);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        giaiQuyet();
    }

    return 0;
}
