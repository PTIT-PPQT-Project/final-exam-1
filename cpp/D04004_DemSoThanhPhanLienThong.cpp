#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int V, E;
vector<int> ke[1001];
bool daTham[1001];

void dfs(int u) {
    daTham[u] = true;
    for (int v : ke[u]) {
        if (!daTham[v]) {
            dfs(v);
        }
    }
}

void giaiQuyet() {
    cin >> V >> E;

    for (int i = 1; i <= V; ++i) {
        ke[i].clear();
    }
    memset(daTham, false, sizeof(daTham));

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }

    int soThanhPhan = 0;
    for (int i = 1; i <= V; ++i) {
        if (!daTham[i]) {
            soThanhPhan++;
            dfs(i);
        }
    }

    cout << soThanhPhan << "\n";
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
