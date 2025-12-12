#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DoanThang {
    int batDau, ketThuc;
};

bool soSanh(DoanThang a, DoanThang b) {
    return a.ketThuc < b.ketThuc;
}

void giaiQuyet() {
    int n;
    cin >> n;
    vector<DoanThang> ds(n);
    for (int i = 0; i < n; ++i) {
        cin >> ds[i].batDau >> ds[i].ketThuc;
    }

    sort(ds.begin(), ds.end(), soSanh);

    int dem = 0;
    int mocKetThuc = -1;

    for (int i = 0; i < n; ++i) {
        if (ds[i].batDau >= mocKetThuc) {
            dem++;
            mocKetThuc = ds[i].ketThuc;
        }
    }
    cout << dem << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        giaiQuyet();
    }
    return 0;
}
