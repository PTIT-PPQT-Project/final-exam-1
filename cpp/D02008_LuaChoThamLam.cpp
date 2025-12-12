#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    if (n == 1 && s == 0) {
        cout << "0 0" << endl;
        return 0;
    }

    if (s == 0 || s > n * 9) {
        cout << "-1 -1" << endl;
        return 0;
    }

    string soLonNhat(n, '0');
    int tongConLai_L = s;
    for (int i = 0; i < n; ++i) {
        int chuSo = min(9, tongConLai_L);
        soLonNhat[i] = chuSo + '0';
        tongConLai_L -= chuSo;
    }

    string soNhoNhat(n, '0');
    int tongConLai_S = s;

    soNhoNhat[0] = '1';
    tongConLai_S -= 1;

    for (int i = n - 1; i >= 1; --i) {
        int chuSo = min(9, tongConLai_S);
        soNhoNhat[i] = chuSo + '0';
        tongConLai_S -= chuSo;
    }

    soNhoNhat[0] = (soNhoNhat[0] - '0' + tongConLai_S) + '0';

    cout << soNhoNhat << " " << soLonNhat << endl;

    return 0;
}
