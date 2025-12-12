#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void giaiQuyet() {
    int n;
    cin >> n;

    vector<double> a(n);
    vector<double> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<int> dp(n, 1);
    int ketQuaToiDa = 0;

    if (n > 0) {
        ketQuaToiDa = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j] && b[i] < b[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ketQuaToiDa = max(ketQuaToiDa, dp[i]);
    }

    cout << ketQuaToiDa << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        giaiQuyet();
    }
    return 0;
}
