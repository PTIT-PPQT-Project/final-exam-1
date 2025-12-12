#include <iostream>
#include <string>

using namespace std;

int n;

void quayLui(string s) {
    if (s.length() == n) {
        bool coA = false;
        bool coB = false;
        for (char c : s) {
            if (c == 'A') {
                coA = true;
            } else if (c == 'B') {
                coB = true;
            }
        }
        
        if (coA && coB) {
            cout << s << endl;
        }
        return;
    }
    
    quayLui(s + 'A');
    quayLui(s + 'B');
}

int main() {
    cin >> n;
    quayLui("");
    return 0;
}
