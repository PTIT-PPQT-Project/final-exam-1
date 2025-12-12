#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool laHopLe(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

void giaiQuyet() {
    string s1, s2;
    cin >> s1 >> s2;
    
    int r1 = s1[1] - '1';
    int c1 = s1[0] - 'a';
    int r2 = s2[1] - '1';
    int c2 = s2[0] - 'a';
    
    if (r1 == r2 && c1 == c2) {
        cout << 0 << endl;
        return;
    }
    
    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<pair<int, int>> q;
    
    q.push({r1, c1});
    dist[r1][c1] = 0;
    
    while (!q.empty()) {
        pair<int, int> hienTai = q.front();
        q.pop();
        
        int r = hienTai.first;
        int c = hienTai.second;
        
        if (r == r2 && c == c2) {
            cout << dist[r][c] << endl;
            return;
        }
        
        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (laHopLe(nr, nc) && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
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
