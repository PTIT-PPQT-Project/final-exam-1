#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void giaiQuyet() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<int>> dist(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    dist[0][0] = 0;
    
    while (!q.empty()) {
        pair<int, int> hienTai = q.front();
        q.pop();
        
        int r = hienTai.first;
        int c = hienTai.second;
        int buoc = dist[r][c];
        int val = a[r][c];
        
        if (r == m - 1 && c == n - 1) {
            break; 
        }
        
        int new_r = r + val;
        if (new_r < m && dist[new_r][c] == -1) {
            dist[new_r][c] = buoc + 1;
            q.push({new_r, c});
        }
        
        int new_c = c + val;
        if (new_c < n && dist[r][new_c] == -1) {
            dist[r][new_c] = buoc + 1;
            q.push({r, new_c});
        }
    }
    
    cout << dist[m - 1][n - 1] << endl;
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
