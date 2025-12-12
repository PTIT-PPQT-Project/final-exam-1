#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long p1 = a[n - 1] * a[n - 2];
    long long p2 = a[0] * a[1];
    long long p3 = a[n - 1] * a[n - 2] * a[n - 3];
    long long p4 = a[0] * a[1] * a[n - 1];

    long long ketQua = max({p1, p2, p3, p4});

    cout << ketQua << endl;

    return 0;
}
