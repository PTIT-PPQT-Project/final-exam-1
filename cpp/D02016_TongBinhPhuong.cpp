#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> dp;

void tienXuLy() {
    int nToiDa = 10000;
    dp.resize(nToiDa + 1);
    
    dp[0] = 0;

    for (int i = 1; i <= nToiDa; ++i) {
        dp[i] = i; 
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }
}

void giaiQuyet() {
    int n;
    cin >> n;
    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    tienXuLy();
    
    int t;
    cin >> t;
    while (t--) {
        giaiQuyet();
    }
    return 0;
}
