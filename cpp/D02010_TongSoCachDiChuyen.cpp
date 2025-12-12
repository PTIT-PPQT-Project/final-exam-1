#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1e9 + 7;

void giaiQuyet() {
    int n, k;
    cin >> n >> k;

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    long long tongCuaSo = 1;

    for (int i = 1; i <= n; ++i) {
        dp[i] = tongCuaSo;
        
        tongCuaSo = (tongCuaSo + dp[i]) % MOD;
        
        if (i >= k) {
            tongCuaSo = (tongCuaSo - dp[i - k] + MOD) % MOD;
        }
    }
    
    cout << dp[n] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        giaiQuyet();
    }
    return 0;
}
