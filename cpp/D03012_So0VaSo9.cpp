#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void giaiQuyet() {
    int n;
    cin >> n;
    
    queue<pair<string, int>> q;
    q.push({"9", 9 % n});
    
    vector<bool> daTham(n, false);
    daTham[9 % n] = true;
    
    while (!q.empty()) {
        pair<string, int> hienTai = q.front();
        q.pop();
        
        string s = hienTai.first;
        int soDu = hienTai.second;
        
        if (soDu == 0) {
            cout << s << endl;
            return;
        }
        
        int soDu0 = (soDu * 10 + 0) % n;
        if (!daTham[soDu0]) {
            daTham[soDu0] = true;
            q.push({s + "0", soDu0});
        }
        
        int soDu9 = (soDu * 10 + 9) % n;
        if (!daTham[soDu9]) {
            daTham[soDu9] = true;
            q.push({s + "9", soDu9});
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
