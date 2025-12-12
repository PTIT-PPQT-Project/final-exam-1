#include <iostream>
#include <string>

using namespace std;

int n;
long long thu_tu = 0;

void quayLui(string s) {
    if (s.length() == n) {
        thu_tu++;
        if (thu_tu % 2 == 0) {
            cout << thu_tu << ": " << s << endl;
        }
        return;
    }
    
    quayLui(s + '0');
    quayLui(s + '1');
    quayLui(s + '2');
}

int main() {
    cin >> n;
    quayLui("");
    return 0;
}
