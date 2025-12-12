#include <iostream>
#include <string>
#include <stack>

using namespace std;

void giaiQuyet() {
    string s;
    cin >> s;
    
    stack<char> st;
    bool coNgoacThua = false;

    for (char c : s) {
        if (c == ')') {
            char top = st.top();
            st.pop();
            
            bool coToanTu = false;
            
            while (!st.empty() && top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    coToanTu = true;
                }
                top = st.top();
                st.pop();
            }
            
            if (!coToanTu) {
                coNgoacThua = true;
                break;
            }
        } else {
            st.push(c);
        }
    }

    if (coNgoacThua) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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
