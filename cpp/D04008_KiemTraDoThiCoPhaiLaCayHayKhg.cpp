#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int so_dinh;
vector<vector<int>> danh_sach_ke;
bool da_tham[1001];

void DFS(int u) {
    da_tham[u] = true;
    for (int v : danh_sach_ke[u]) {
        if (!da_tham[v]) {
            DFS(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int so_test;
    cin >> so_test;
    while (so_test--) {
        cin >> so_dinh;
        int so_canh = so_dinh - 1;

        danh_sach_ke.assign(so_dinh + 1, vector<int>());
        memset(da_tham, false, sizeof(da_tham));

        for (int i = 0; i < so_canh; ++i) {
            int u, v;
            cin >> u >> v;
            danh_sach_ke[u].push_back(v);
            danh_sach_ke[v].push_back(u);
        }

        if (so_dinh == 0) {
            cout << "YES\n";
            continue;
        }

        DFS(1);

        bool lien_thong = true;
        for (int i = 1; i <= so_dinh; ++i) {
            if (!da_tham[i]) {
                lien_thong = false;
                break;
            }
        }

        if (lien_thong) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
