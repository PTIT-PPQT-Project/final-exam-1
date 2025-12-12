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

    cin >> so_dinh >> so_canh;

    danh_sach_ke.assign(so_dinh + 1, vector<int>());
    memset(da_tham, false, sizeof(da_tham));

    for (int i = 0; i < so_canh; ++i) {
        int u, v;
        cin >> u >> v;
        danh_sach_ke[u].push_back(v);
        danh_sach_ke[v].push_back(u);
    }

    int kich_thuoc_tp_cua_1 = DFS(1);
    int kich_thuoc_lon_nhat_khac = 0;

    for (int i = 2; i <= so_dinh; ++i) {
        if (!da_tham[i]) {
            int kich_thuoc_hien_tai = DFS(i);
            kich_thuoc_lon_nhat_khac = max(kich_thuoc_lon_nhat_khac, kich_thuoc_hien_tai);
        }
    }

    cout << kich_thuoc_tp_cua_1 + kich_thuoc_lon_nhat_khac << "\n";

    return 0;
}
