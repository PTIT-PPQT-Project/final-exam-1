#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

string xoayTrai(string s) {
    string moi = s;
    moi[0] = s[3];
    moi[1] = s[0];
    moi[3] = s[4];
    moi[4] = s[1];
    return moi;
}

string xoayPhai(string s) {
    string moi = s;
    moi[1] = s[4];
    moi[2] = s[1];
    moi[4] = s[5];
    moi[5] = s[2];
    return moi;
}

void giaiQuyet() {
    string batDau = "      ";
    string ketThuc = "      ";
    int val;
    
    for (int i = 0; i < 6; ++i) {
        cin >> val;
        batDau[i] = val + '0';
    }
    for (int i = 0; i < 6; ++i) {
        cin >> val;
        ketThuc[i] = val + '0';
    }
    
    queue<pair<string, int>> q;
    map<string, int> dist;
    
    q.push({batDau, 0});
    dist[batDau] = 0;
    
    while (!q.empty()) {
        pair<string, int> hienTai = q.front();
        q.pop();
        
        string trangThai = hienTai.first;
        int buoc = hienTai.second;
        
        if (trangThai == ketThuc) {
            cout << buoc << endl;
            return;
        }
        
        string trangThaiTrai = xoayTrai(trangThai);
        if (dist.find(trangThaiTrai) == dist.end()) {
            dist[trangThaiTrai] = buoc + 1;
            q.push({trangThaiTrai, buoc + 1});
        }
        
        string trangThaiPhai = xoayPhai(trangThai);
        if (dist.find(trangThaiPhai) == dist.end()) {
            dist[trangThaiPhai] = buoc + 1;
            q.push({trangThaiPhai, buoc + 1});
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
