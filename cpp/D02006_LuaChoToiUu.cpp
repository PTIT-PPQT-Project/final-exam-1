#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct CongViec {
    int batDau, ketThuc;
};

bool soSanh(CongViec a, CongViec b) {
    return a.ketThuc < b.ketThuc;
}

void giaiQuyet() {
    int n;
    cin >> n;
    vector<CongViec> cv(n);
    for (int i = 0; i < n; ++i) {
        cin >> cv[i].batDau >> cv[i].ketThuc;
    }

    sort(cv.begin(), cv.end(), soSanh);

    int dem = 0;
    int thoiGianCuoi = 0; 

    for (int i = 0; i < n; ++i) {
        if (cv[i].batDau >= thoiGianCuoi) {
            dem++;
            thoiGianCuoi = cv[i].ketThuc;
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
