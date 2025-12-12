#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int so_dinh, so_canh;
vector<vector<int>> danh_sach_ke;
bool da_tham[1001];

bool DFS(int u, int cha) {
    da_tham[u] = true;

    for (int v : danh_sach_ke[u]) {
        if (v == cha) {
            continue;
        }
        
        if (da_tham[v]) {
            return true;
        }

        if (DFS(v, u)) {
            return true;
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int so_test;
    cin >> so_test;
    while (so_test--) {
        cin >> so_dinh >> so_canh;

        danh_sach_ke.assign(so_dinh + 1, vector<int>());
        memset(da_tham, false, sizeof(da_tham));

        for (int i = 0; i < so_canh; ++i) {
            int u, v;
            cin >> u >> v;
            danh_sach_ke[u].push_back(v);
            danh_sach_ke[v].push_back(u);
        }

        bool co_chu_trinh = false;
        for (int i = 1; i <= so_dinh; ++i) {
            if (!da_tham[i]) {
                if (DFS(i, 0)) {
                    co_chu_trinh = true;
                    break;
                }
            }
        }

        if (co_chu_trinh) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
