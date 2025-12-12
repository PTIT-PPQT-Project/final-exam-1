#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int so_dinh;
vector<vector<int>> danh_sach_ke;
bool da_tham[100001];
vector<int> thanh_phan_hien_tai;

void DFS(int u) {
    da_tham[u] = true;
    thanh_phan_hien_tai.push_back(u);
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
        int so_canh;
        cin >> so_dinh >> so_canh;

        danh_sach_ke.assign(so_dinh + 1, vector<int>());
        memset(da_tham, false, sizeof(bool) * (so_dinh + 1));

        for (int i = 0; i < so_canh; ++i) {
            int u, v;
            cin >> u >> v;
            danh_sach_ke[u].push_back(v);
            danh_sach_ke[v].push_back(u);
        }

        bool hoan_hao = true;
        for (int i = 1; i <= so_dinh; ++i) {
            if (!da_tham[i]) {
                thanh_phan_hien_tai.clear();
                DFS(i);

                int kich_thuoc = thanh_phan_hien_tai.size();
                if (kich_thuoc == 1) {
                    continue;
                }

                for (int u : thanh_phan_hien_tai) {
                    if (danh_sach_ke[u].size() != kich_thuoc - 1) {
                        hoan_hao = false;
                        break;
                    }
                }
            }
            if (!hoan_hao) {
                break;
            }
        }

        if (hoan_hao) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
