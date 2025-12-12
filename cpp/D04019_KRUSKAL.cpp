#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Canh {
    int u, v, w;
    bool operator<(const Canh& other) const {
        return w < other.w;
    }
};

vector<int> cha;

int tim(int i) {
    if (cha[i] == i)
        return i;
    return cha[i] = tim(cha[i]);
}

bool hopNhat(int i, int j) {
    int goc_i = tim(i);
    int goc_j = tim(j);
    if (goc_i != goc_j) {
        cha[goc_i] = goc_j;
        return true;
    }
    return false;
}

void giaiQuyet() {
    int soDinh, soCanh;
    cin >> soDinh >> soCanh;

    vector<Canh> danhSachCanh(soCanh);
    for (int i = 0; i < soCanh; ++i) {
        cin >> danhSachCanh[i].u >> danhSachCanh[i].v >> danhSachCanh[i].w;
    }

    sort(danhSachCanh.begin(), danhSachCanh.end());

    cha.resize(soDinh + 1);
    iota(cha.begin() + 1, cha.end(), 1);

    long long tongTrongSo = 0;
    int soCanhDaThem = 0;

    for (const auto& canh : danhSachCanh) {
        if (hopNhat(canh.u, canh.v)) {
            tongTrongSo += canh.w;
            soCanhDaThem++;
        }
        if (soCanhDaThem == soDinh - 1) {
            break;
        }
    }
    cout << tongTrongSo << "\n";
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
