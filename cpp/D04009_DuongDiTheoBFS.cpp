#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int so_dinh, so_canh, dinh_xuat_phat;
vector<vector<int>> danh_sach_ke;
bool da_tham[1001];
int truoc[1001];

void BFS(int s) {
    queue<int> q;
    q.push(s);
    da_tham[s] = true;
    truoc[s] = 0; 

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : danh_sach_ke[u]) {
            if (!da_tham[v]) {
                da_tham[v] = true;
                truoc[v] = u;
                q.push(v);
            }
        }
    }
}

void in_duong_di(int i) {
    vector<int> duong_di;
    int t = i;
    while (t != 0) {
        duong_di.push_back(t);
        t = truoc[t];
    }
    reverse(duong_di.begin(), duong_di.end());
    for (int dinh : duong_di) {
        cout << dinh << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int so_test;
    cin >> so_test;
    while (so_test--) {
        cin >> so_dinh >> so_canh >> dinh_xuat_phat;

        danh_sach_ke.assign(so_dinh + 1, vector<int>());
        memset(da_tham, false, sizeof(da_tham));
        memset(truoc, 0, sizeof(truoc));

        for (int i = 0; i < so_canh; ++i) {
            int u, v;
            cin >> u >> v;
            danh_sach_ke[u].push_back(v);
            danh_sach_ke[v].push_back(u);
        }

        BFS(dinh_xuat_phat);

        for (int i = 1; i <= so_dinh; ++i) {
            if (i == dinh_xuat_phat) {
                continue;
            }

            if (!da_tham[i]) {
                cout << "No path\n";
            } else {
                in_duong_di(i);
            }
        }
    }
    return 0;
}
