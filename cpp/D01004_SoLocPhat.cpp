#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    queue<string> q;
    q.push("6");
    q.push("8");
    
    vector<string> results;
    
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        
        if (current.length() == n) {
            results.push_back(current);
        } else if (current.length() < n) {
            q.push(current + "6");
            q.push(current + "8");
        }
    }
    
    cout << results.size() << endl;
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << (i == results.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
