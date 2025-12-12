#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void findSubsequences(const string& s, int index, string current, vector<string>& result) {
    if (index == s.length()) {
        if (!current.empty()) {
            result.push_back(current);
        }
        return;
    }

    findSubsequences(s, index + 1, current + s[index], result);
    findSubsequences(s, index + 1, current, result);
}

void solve() {
    int length;
    if (!(cin >> length)) return; 
    
    string s;
    cin >> s;

    vector<string> result;
    findSubsequences(s, 0, "", result);

    sort(result.begin(), result.end());

    for (const string& sub : result) {
        cout << sub << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        solve();
    }

    return 0;
}