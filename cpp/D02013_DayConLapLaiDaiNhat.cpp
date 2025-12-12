#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i <= n - l; ++i) {
            int j = i + l - 1;
            
            if (s[i] == s[j]) {
                if (l == 2 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
    }

    int m;
    cin >> m;

    while (m--) {
        int l, r;
        cin >> l >> r;
        
        if (dp[l - 1][r - 1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
