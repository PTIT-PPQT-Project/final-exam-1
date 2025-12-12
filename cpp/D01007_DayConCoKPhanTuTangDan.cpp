#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> a;

void in_day_con(const vector<int>& day_con) {
    for (int i = 0; i < day_con.size(); ++i) {
        cout << day_con[i] << (i == day_con.size() - 1 ? "" : " ");
    }
    cout << endl;
}

void quayLui(int startIndex, vector<int>& current_combo) {
    if (current_combo.size() == k) {
        in_day_con(current_combo);
        return;
    }
    
    for (int i = startIndex; i < n; ++i) {
        current_combo.push_back(a[i]);
        quayLui(i + 1, current_combo);
        current_combo.pop_back();
    }
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    vector<int> current_combo;
    quayLui(0, current_combo);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
