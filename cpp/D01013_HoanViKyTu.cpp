#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;
bool daDung[11];
vector<char> hoanViHienTai;

void lietKeHoanVi() {
    if (hoanViHienTai.size() == s.length()) {
        for (char ch : hoanViHienTai) {
            cout << ch;
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < s.length(); ++i) {
        if (!daDung[i]) {
            daDung[i] = true;
            hoanViHienTai.push_back(s[i]);
            
            lietKeHoanVi();
            
            hoanViHienTai.pop_back();
            daDung[i] = false;
        }
    }
}

void giaiQuyet() {
    char c1, c2;
    cin >> c1 >> c2;

    if (c1 > c2) {
        swap(c1, c2);
    }

    s = "";
    for (char ch = c1; ch <= c2; ++ch) {
        s += ch;
    }

    for(int i=0; i<s.length(); ++i) {
        daDung[i] = false;
    }
    hoanViHienTai.clear();

    lietKeHoanVi();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    giaiQuyet();

    return 0;
}
