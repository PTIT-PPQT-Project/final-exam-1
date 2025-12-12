#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void giaiQuyet() {
    int n;
    cin >> n;
    
    vector<string> ketQua;
    queue<string> hangDoi;
    
    hangDoi.push("6");
    hangDoi.push("8");
    
    while (true) {
        string hienTai = hangDoi.front();
        hangDoi.pop();
        
        if (hienTai.length() > n) {
            break;
        }
        
        ketQua.push_back(hienTai);
        
        hangDoi.push(hienTai + "6");
        hangDoi.push(hienTai + "8");
    }
    
    cout << ketQua.size() << endl;
    for (const string& s : ketQua) {
        cout << s << " ";
    }
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
