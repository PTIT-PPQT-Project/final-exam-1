#include <iostream>
#include <vector>

using namespace std;

int n, k;
int thuTu = 0;
vector<int> a;
vector<bool> sang;

void taoSang(int gioiHan) {
    sang.assign(gioiHan + 1, false);
    sang[0] = sang[1] = true;
    for (int p = 2; p * p <= gioiHan; p++) {
        if (!sang[p]) {
            for (int i = p * p; i <= gioiHan; i += p)
                sang[i] = true;
        }
    }
}

void inKetQua() {
    thuTu++;
    if (!sang[thuTu]) {
        cout << thuTu << ":";
        for (int i = 1; i <= k; ++i) {
            cout << " " << a[i];
        }
        cout << endl;
    }
}

void quayLui(int i, int batDau) {
    for (int j = batDau; j <= n; ++j) {
        a[i] = j;
        if (i == k) {
            inKetQua();
        } else {
            quayLui(i + 1, j + 1);
        }
    }
}

int main() {
    cin >> n >> k;
    a.resize(k + 1);
    taoSang(100000); 
    quayLui(1, 1);
    return 0;
}
