#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int k;
string s;
set<string> ketQua;

void quayLui(int batDau, string soHienTai) {
    if (soHienTai.length() == k) {
        ketQua.insert(soHienTai);
        return;
    }

    for (int j = batDau; j < s.length(); ++j) {
        quayLui(j + 1, soHienTai + s[j]);
    }
}

void giaiQuyet() {
    cin >> s >> k;
    ketQua.clear(); 
    
    quayLui(0, "");

    for (const string& so : ketQua) {
        cout << so << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        giaiQuyet();
    }
    return 0;
}
