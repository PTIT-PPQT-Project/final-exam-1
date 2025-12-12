#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int giaiQuyet() {
    int n;
    cin >> n;
    
    if (n == 1) {
        return 0;
    }
    
    queue<pair<int, int>> q;
    q.push({n, 0});
    
    map<int, int> dist;
    dist[n] = 0;
    
    while (!q.empty()) {
        pair<int, int> hienTai = q.front();
        q.pop();
        
        int giaTri = hienTai.first;
        int buoc = hienTai.second;
        
        if (giaTri == 1) {
            return buoc;
        }
        
        int giaTriMoi_a = giaTri - 1;
        if (giaTriMoi_a > 0) {
            if (dist.find(giaTriMoi_a) == dist.end()) {
                dist[giaTriMoi_a] = buoc + 1;
                q.push({giaTriMoi_a, buoc + 1});
            }
        }
        
        for (int i = 2; (long long)i * i <= giaTri; ++i) {
            if (giaTri % i == 0) {
                int giaTriMoi_b = giaTri / i;
                
                if (dist.find(giaTriMoi_b) == dist.end()) {
                    dist[giaTriMoi_b] = buoc + 1;
                    q.push({giaTriMoi_b, buoc + 1});
                }
            }
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int soTest;
    cin >> soTest;
    while (soTest--) {
        cout << giaiQuyet() << endl;
    }
    return 0;
}
