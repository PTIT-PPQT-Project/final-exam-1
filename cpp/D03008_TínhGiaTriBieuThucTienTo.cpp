#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int viTri;

long long tinhToan(string &bieuThuc) {
    char kyTu = bieuThuc[viTri];
    viTri++;

    if (kyTu == '+') {
        long long toanHang1 = tinhToan(bieuThuc);
        long long toanHang2 = tinhToan(bieuThuc);
        return toanHang1 + toanHang2;
    } else if (kyTu == '-') {
        long long toanHang1 = tinhToan(bieuThuc);
        long long toanHang2 = tinhToan(bieuThuc);
        return toanHang1 - toanHang2;
    } else if (kyTu == '*') {
        long long toanHang1 = tinhToan(bieuThuc);
        long long toanHang2 = tinhToan(bieuThuc);
        return toanHang1 * toanHang2;
    } else if (kyTu == '/') {
        long long toanHang1 = tinhToan(bieuThuc);
        long long toanHang2 = tinhToan(bieuThuc);
        return toanHang1 / toanHang2;
    } else {
        return (long long)(kyTu - '0');
    }
}

void giaiQuyet() {
    string bieuThuc;
    cin >> bieuThuc;
    viTri = 0;
    cout << tinhToan(bieuThuc) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        giaiQuyet();
    }
    return 0;
}
