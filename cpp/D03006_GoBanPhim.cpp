#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    list<char> vanBan;
    auto conTro = vanBan.end();

    for (char kyTu : s) {
        if (kyTu == '<') {
            if (conTro != vanBan.begin()) {
                conTro--;
            }
        } else if (kyTu == '>') {
            if (conTro != vanBan.end()) {
                conTro++;
            }
        } else if (kyTu == '-') {
            if (conTro != vanBan.begin()) {
                conTro = vanBan.erase(prev(conTro));
            }
        } else {
            vanBan.insert(conTro, kyTu);
        }
    }

    for (char kyTu : vanBan) {
        cout << kyTu;
    }
    cout << "\n";

    return 0;
}
