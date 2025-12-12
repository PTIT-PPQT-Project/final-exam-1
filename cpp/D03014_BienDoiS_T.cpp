#include <iostream>
#include <queue>
#include <map>

using namespace std;

void giaiQuyet() {
    int s, t;
    cin >> s >> t;
    
    queue<pair<int, int>> q;
    q.push({s, 0});
    
    map<int, int> daTham;
    daTham[s] = 0;
    
    while (!q.empty()) {
        pair<int, int> hienTai = q.front();
        q.pop();
        
        int giaTri = hienTai.first;
        int buoc = hienTai.second;
        
        if (giaTri == t) {
            cout << buoc << endl;
            return;
        }
        
        int tru1 = giaTri - 1;
        if (tru1 > 0 && daTham.find(tru1) == daTham.end()) {
            daTham[tru1] = buoc + 1;
            q.push({tru1, buoc + 1});
        }
        
        int nhan2 = giaTri * 2;
        if (giaTri < t && nhan2 < 2 * t && daTham.find(nhan2) == daTham.end()) {
             daTham[nhan2] = buoc + 1;
             q.push({nhan2, buoc + 1});
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
