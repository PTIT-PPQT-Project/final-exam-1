#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n, k;
string s;
set<long long> results;

void quayLui(int startIndex, string currentNumStr) {
    if (currentNumStr.length() == k) {
        results.insert(stoll(currentNumStr));
        return;
    }
    
    for (int i = startIndex; i < n; ++i) {
        quayLui(i + 1, currentNumStr + s[i]);
    }
}

void solve() {
    cin >> s >> k;
    n = s.length();
    results.clear();
    
    quayLui(0, "");
    
    for (long long num : results) {
        cout << num << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
