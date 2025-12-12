#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n <= 2 || n >= 15) {
        return 0;
    }

    long long gioiHan = 1LL << n;

    set<long long> tapFib;
    long long f1 = 1;
    long long f2 = 2;

    if (f1 <= gioiHan) {
        tapFib.insert(f1);
    }
    
    while (f2 <= gioiHan) {
        tapFib.insert(f2);
        long long tam = f1 + f2;
        f1 = f2;
        f2 = tam;
    }

    for (long long k = 1; k <= gioiHan; k++) {
        if (tapFib.count(k)) {
            cout << k << ": ";

            vector<int> bit(n, 0);
            long long so = k - 1;
            int viTri = n - 1;

            while (so > 0) {
                bit[viTri] = so % 2;
                so = so / 2;
                viTri--;
            }

            cout << bit[0];
            for (int i = 1; i < n; i++) {
                cout << " " << bit[i];
            }
            cout << endl;
        }
    }

    return 0;
}
