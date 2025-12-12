#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> a;

void inKetQua() {
    for (int i = 1; i <= k; ++i) {
        cout << a[i] << (i == k ? "" : " ");
    }
    cout << endl;
}

void quayLui(int i, int batDau) {
    for (int j = batDau; j <= n; ++j) {
        a[i] = j;
        if (i == k) {
            inKetQua();
        } else {
            quayLui(i + 1, j);
        }
    }
}

int main() {
    cin >> n >> k;
    a.resize(k + 1);
    quayLui(1, 1);
    return 0;
}
