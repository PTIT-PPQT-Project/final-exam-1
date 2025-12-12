#include <iostream>
#include <vector>

using namespace std;

int n, m;
int hoanVi[10];
bool daDung[10];

void inHoanVi() {
    for (int i = 1; i <= n; i++) {
        cout << hoanVi[i] << " ";
    }
    cout << endl;
}

void lietKe(int viTri) {
    if (viTri == n) {
        inHoanVi();
        return;
    }

    for (int giaTri = 1; giaTri <= n; giaTri++) {
        if (!daDung[giaTri]) {
            hoanVi[viTri] = giaTri;
            daDung[giaTri] = true;

            lietKe(viTri + 1);

            daDung[giaTri] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        daDung[i] = false;
    }

    hoanVi[n] = m;
    daDung[m] = true;

    lietKe(1);

    return 0;
}
