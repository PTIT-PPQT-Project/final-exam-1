#include <iostream>
#include <vector>

using namespace std;

int n, k;
int thuTu = 0;
vector<int> a;

void inKetQua() {
    if (thuTu % k == 0) {
        for (int i = 1; i <= k; ++i) {
            cout << a[i] << (i == k ? "" : " ");
        }
        cout << endl;
    }
    thuTu++;
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
    quayLui(1, 1);
    return 0;
}
