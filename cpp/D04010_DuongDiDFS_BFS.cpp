#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
vector<int> danhSachKe[1001];
bool daTham[1001];
int truoc[1001];

void dfs(int u) {
    daTham[u] = true;
    for (int v : danhSachKe[u]) {
        if (!daTham[v]) {
            truoc[v] = u;
            dfs(v);
        }
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    daTham[u] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int x : danhSachKe[v]) {
            if (!daTham[x]) {
                daTham[x] = true;
                truoc[x] = v;
                q.push(x);
            }
        }
    }
}

void inDuongDi(int batDau, int ketThuc) {
    if (!daTham[ketThuc]) {
        cout << -1;
        return;
    }

    vector<int> duongDi;
    int hienTai = ketThuc;
    while (hienTai != batDau) {
        duongDi.push_back(hienTai);
        hienTai = truoc[hienTai];
    }
    duongDi.push_back(batDau);
    
    reverse(duongDi.begin(), duongDi.end());

    for (size_t i = 0; i < duongDi.size(); ++i) {
        cout << duongDi[i] << (i == duongDi.size() - 1 ? "" : " ");
    }
}

void giaiQuyet() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        danhSachKe[i].clear();
    }
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        danhSachKe[u].push_back(v);
        danhSachKe[v].push_back(u);
    }

    for (int i = 2; i <= N; ++i) {
        memset(daTham, false, sizeof(daTham));
        memset(truoc, 0, sizeof(truoc));
        dfs(1);
        inDuongDi(1, i);
        cout << "\n";

        memset(daTham, false, sizeof(daTham));
        memset(truoc, 0, sizeof(truoc));
        bfs(i);
        inDuongDi(i, 1);
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    giaiQuyet();
    
    return 0;
}
