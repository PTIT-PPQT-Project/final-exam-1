#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> target_combo;
long long count;
bool found;

void quayLui(int start_val, vector<int>& current_combo) {
    if (found) {
        return;
    }

    if (current_combo.size() == k) {
        count++;
        
        bool match = true;
        for (int i = 0; i < k; ++i) {
            if (current_combo[i] != target_combo[i]) {
                match = false;
                break;
            }
        }
        
        if (match) {
            cout << count << endl;
            found = true;
        }
        return;
    }
    
    for (int i = start_val; i <= n; ++i) {
        if ((n - i + 1) < (k - current_combo.size())) {
            break;
        }
        
        current_combo.push_back(i);
        quayLui(i + 1, current_combo);
        current_combo.pop_back();
        
        if (found) {
            return;
        }
    }
}

void solve() {
    cin >> n >> k;
    target_combo.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> target_combo[i];
    }
    
    count = 0;
    found = false;
    vector<int> current_combo;
    
    quayLui(1, current_combo);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
