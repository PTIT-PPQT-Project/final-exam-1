#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void giaiQuyet() {
    string s;
    cin >> s;
    
    stack<int> st;
    st.push(-1);
    int doDaiLonNhat = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                doDaiLonNhat = max(doDaiLonNhat, i - st.top());
            }
        }
    }
    
    cout << doDaiLonNhat << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        giaiQuyet();
    }
    return 0;
}
