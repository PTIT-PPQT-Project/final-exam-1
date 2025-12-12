#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n;
vector<string> tu;
set<string> ketQua;

void quayLui(int index, string chuoiHienTai) {
    if (index == n) {
        return;
    }
    
    quayLui(index + 1, chuoiHienTai);

    string chuoiMoi = chuoiHienTai + tu[index];
    ketQua.insert(chuoiMoi);
    quayLui(index + 1, chuoiMoi);
}

int main() {
    cin >> n;
    tu.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> tu[i];
    }

    for (int i = 0; i < n; ++i) {
        ketQua.insert(tu[i]);
        quayLui(i + 1, tu[i]);
    }

    for (const string& s : ketQua) {
        cout << s << endl;
    }

    return 0;
}
