#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void giaiQuyet() {
    int n;
    cin >> n;

    vector<long long> h(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    h[n] = 0;

    long long dienTichLonNhat = 0;
    stack<int> s;

    for (int i = 0; i <= n; i++) {
        while (!s.empty() && h[s.top()] >= h[i]) {
            long long chieuCao = h[s.top()];
            s.pop();

            int chieuRong;
            if (s.empty()) {
                chieuRong = i;
            } else {
                chieuRong = i - s.top() - 1;
            }

            dienTichLonNhat = max(dienTichLonNhat, chieuCao * chieuRong);
        }
        s.push(i);
    }

    cout << dienTichLonNhat << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        giaiQuyet();
    }
    return 0;
}
