#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int so_dinh, so_canh;
vector<vector<int>> danh_sach_ke;
int so[1001], thap[1001];
bool da_tham[1001];
int thoi_gian;
vector<pair<int, int>> danh_sach_cau;

void DFS(int u, int cha) {
    da_tham[u] = true;
    so[u] = thap[u] = ++thoi_gian;

    for (int v : danh_sach_ke[u]) {
        if (v == cha) {
            continue;
        }
        if (da_tham[v]) {
            thap[u] = min(thap[u], so[v]);
        } else {
            DFS(v, u);
            thap[u] = min(thap[u], thap[v]);

            if (thap[v] > so[u]) {
                if (u < v) {
                    danh_sach_cau.push_back({u, v});
                } else {
                    danh_sach_cau.push_back({v, u});
                }
            }
        }
    }
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
        memset(so, 0, sizeof(so));
        memset(thap, 0, sizeof(thap));
        danh_sach_cau.clear();
        thoi_gian = 0;

        for (int i = 0; i < so_canh; ++i) {
            int u, v;
            cin >> u >> v;
            danh_sach_ke[u].push_back(v);
            danh_sach_ke[v].push_back(u);
        }

        for (int i = 1; i <= so_dinh; ++i) {
            if (!da_tham[i]) {
                DFS(i, 0);
            }
        }

        sort(danh_sach_cau.begin(), danh_sach_cau.end());

        for (const auto& cau : danh_sach_cau) {
            cout << cau.first << " " << cau.second << " ";
        }
        cout << "\n";
    }
    return 0;
}
