#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n, k;
vector<string> cacTu;
set<string> ketQua;

void quayLui(int batDau, int soLuongDaChon, string chuoiHienTai) {
    if (soLuongDaChon == k) {
        ketQua.insert(chuoiHienTai);
        return;
    }

    for (int j = batDau; j < n; ++j) {
        quayLui(j + 1, soLuongDaChon + 1, chuoiHienTai + cacTu[j]);
    }
}

int main() {
    cin >> n >> k;
    cacTu.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cacTu[i];
    }

    quayLui(0, 0, "");

    for (const string& s : ketQua) {
        cout << s << endl;
    }

    return 0;
}
