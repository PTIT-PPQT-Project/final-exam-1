#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void giaiQuyet() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[0] << endl;
        return;
    }

    vector<long long> dp(n);
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], a[i] + dp[i - 2]);
    }

    cout << dp[n - 1] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        giaiQuyet();
    }
    return 0;
}
