#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n;
vector<string> a;
set<string> ketQua;

void quayLui(int batDau, string chuoiHienTai) {
    for (int j = batDau; j < n; ++j) {
        string chuoiMoi = chuoiHienTai + a[j];
        ketQua.insert(chuoiMoi);
        quayLui(j + 1, chuoiMoi);
    }
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        ketQua.insert(a[i]);
        quayLui(i + 1, a[i]);
    }

    for (const string& s : ketQua) {
        cout << s << endl;
    }

    return 0;
}
