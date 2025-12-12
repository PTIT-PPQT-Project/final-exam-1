#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n, k;
vector<string> a;
set<string> ketQua;

void quayLui(int batDau, int soLuongDaChon, string chuoiHienTai) {
    if (soLuongDaChon == k) {
        ketQua.insert(chuoiHienTai);
        return;
    }

    for (int j = batDau; j < n; ++j) {
        quayLui(j + 1, soLuongDaChon + 1, chuoiHienTai + a[j]);
    }
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    quayLui(0, 0, "");

    for (const string& s : ketQua) {
        cout << s << endl;
    }

    return 0;
}
