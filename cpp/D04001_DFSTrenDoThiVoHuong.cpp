#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e, u;
vector<vector<int>> ke;
vector<bool> daTham;

void DFS(int i) {
    cout << i << " ";
    daTham[i] = true;
    
    for (int j : ke[i]) {
        if (!daTham[j]) {
            DFS(j);
        }
    }
}

void giaiQuyet() {
    cin >> v >> e >> u;
    
    ke.assign(v + 1, vector<int>());
    daTham.assign(v + 1, false);
    
    for (int i = 0; i < e; ++i) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    
    for (int i = 1; i <= v; ++i) {
        sort(ke[i].begin(), ke[i].end());
    }
    
    DFS(u);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int soTest;
    cin >> soTest;
    while (soTest--) {
        giaiQuyet();
    }
    return 0;
}
