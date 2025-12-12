#include <iostream>
#include <string>
#include <stack>

using namespace std;

void giaiQuyet() {
    string s;
    cin >> s;

    int moNgoac = 0;
    int tongChieuDai = 0;

    for (char kyTu : s) {
        if (kyTu == '(') {
            moNgoac++;
        } else if (kyTu == ')') {
            if (moNgoac > 0) {
                moNgoac--;
                tongChieuDai += 2;
            }
        }
    }
    cout << tongChieuDai << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        giaiQuyet();
    }
    return 0;
}
