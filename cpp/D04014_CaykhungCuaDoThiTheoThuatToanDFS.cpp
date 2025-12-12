#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, u;
vector<int> ke[1001];
bool daTham[1001];
vector<pair<int, int>> cayKhung;

void dfs(int u) {
    daTham[u] = true;
    for (int v : ke[u]) {
        if (!daTham[v]) {
            cayKhung.push_back({u, v});
            dfs(v);
        }
    }
}

void giaiQuyet() {
    cin >> N >> M >> u;

    for (int i = 1; i <= N; i++) {
        ke[i].clear();
    }
    memset(daTham, false, sizeof(daTham));
    cayKhung.clear();

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ke[a].push_back(b);
        ke[b].push_back(a);
    }

    dfs(u);

    if (cayKhung.size() == N - 1) {
        for (auto canh : cayKhung) {
            cout << canh.first << " " << canh.second << "\n";
        }
    } else {
        cout << "-1\n";
    }
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
