#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

void giaiQuyet() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    
    map<char, int> tanSuat;
    for (char c : s) {
        tanSuat[c]++;
    }
    
    priority_queue<int> hangDoiUuTien;
    for (auto const& [kyTu, dem] : tanSuat) {
        hangDoiUuTien.push(dem);
    }
    
    while (k > 0 && !hangDoiUuTien.empty()) {
        int demLonNhat = hangDoiUuTien.top();
        hangDoiUuTien.pop();
        
        demLonNhat--;
        if (demLonNhat > 0) {
            hangDoiUuTien.push(demLonNhat);
        }
        
        k--;
    }
    
    long long giaTriNhoNhat = 0;
    while (!hangDoiUuTien.empty()) {
        int dem = hangDoiUuTien.top();
        hangDoiUuTien.pop();
        giaTriNhoNhat += (long long)dem * dem;
    }
    
    cout << giaTriNhoNhat << endl;
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
