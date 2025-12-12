#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int so_dinh, so_canh;
vector<vector<int>> danh_sach_ke;
bool da_tham[100001];

int DFS(int u) {
    da_tham[u] = true;
    int kich_thuoc = 1; 

    for (int v : danh_sach_ke[u]) {
        if (!da_tham[v]) {
            kich_thuoc += DFS(v);
        }
    }
    return kich_thuoc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int so_test;
    cin >> so_test;
    while (so_test--) {
        cin >> so_dinh >> so_canh;

        danh_sach_ke.assign(so_dinh + 1, vector<int>());
        memset(da_tham, false, sizeof(bool) * (so_dinh + 1));

        for (int i = 0; i < so_canh; ++i) {
            int u, v;
            cin >> u >> v;
            danh_sach_ke[u].push_back(v);
            danh_sach_ke[v].push_back(u);
        }

        int kich_thuoc_lon_nhat = 0;
        for (int i = 1; i <= so_dinh; ++i) {
            if (!da_tham[i]) {
                int kich_thuoc_thanh_phan = DFS(i);
                kich_thuoc_lon_nhat = max(kich_thuoc_lon_nhat, kich_thuoc_thanh_phan);
            }
        }

        cout << kich_thuoc_lon_nhat << "\n";
    }
    return 0;
}
