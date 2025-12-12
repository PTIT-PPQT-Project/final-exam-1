#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void giaiQuyet() {
    int n;
    cin >> n;
    
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    
    q.push({r1, c1});
    dist[r1][c1] = 0;
    
    while (!q.empty()) {
        pair<int, int> hienTai = q.front();
        q.pop();
        
        int r = hienTai.first;
        int c = hienTai.second;
        int buoc = dist[r][c];
        
        if (r == r2 && c == c2) {
            cout << buoc << endl;
            return;
        }
        
        for (int j = c - 1; j >= 0; --j) {
            if (grid[r][j] == 'X') break;
            if (dist[r][j] == -1) {
                dist[r][j] = buoc + 1;
                q.push({r, j});
            }
        }
        
        for (int j = c + 1; j < n; ++j) {
            if (grid[r][j] == 'X') break;
            if (dist[r][j] == -1) {
                dist[r][j] = buoc + 1;
                q.push({r, j});
            }
        }
        
        for (int i = r - 1; i >= 0; --i) {
            if (grid[i][c] == 'X') break;
            if (dist[i][c] == -1) {
                dist[i][c] = buoc + 1;
                q.push({i, c});
            }
        }
        
        for (int i = r + 1; i < n; ++i) {
            if (grid[i][c] == 'X') break;
            if (dist[i][c] == -1) {
                dist[i][c] = buoc + 1;
                q.push({i, c});
            }
        }
    }
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
