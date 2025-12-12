#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int V, E;
vector<int> ke[1001];
int disc[1001], low[1001];
bool visited[1001];
bool is_ap[1001];
int timer;

void dfs(int u, int p) {
    visited[u] = true;
    disc[u] = low[u] = timer++;
    int children = 0;

    for (int v : ke[u]) {
        if (v == p) {
            continue;
        }
        
        if (visited[v]) {
            low[u] = min(low[u], disc[v]);
        } else {
            children++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (p != -1 && low[v] >= disc[u]) {
                is_ap[u] = true;
            }
        }
    }

    if (p == -1 && children > 1) {
        is_ap[u] = true;
    }
}

void giaiQuyet() {
    cin >> V >> E;
    for (int i = 1; i <= V; ++i) {
        ke[i].clear();
    }
    memset(visited, false, sizeof(visited));
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    memset(is_ap, false, sizeof(is_ap));
    timer = 0;

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }

    for (int i = 1; i <= V; ++i) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (is_ap[i]) {
            cout << i << " ";
        }
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
