#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

long long tinhGiaTriHauTo(string s) {
    stack<long long> st;

    for (char c : s) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            long long toanHang2 = st.top();
            st.pop();
            long long toanHang1 = st.top();
            st.pop();

            if (c == '+') {
                st.push(toanHang1 + toanHang2);
            } else if (c == '-') {
                st.push(toanHang1 - toanHang2);
            } else if (c == '*') {
                st.push(toanHang1 * toanHang2);
            } else if (c == '/') {
                st.push(toanHang1 / toanHang2);
            }
        }
    }
    return st.top();
}

void giaiQuyet() {
    string s;
    cin >> s;
    cout << tinhGiaTriHauTo(s) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        giaiQuyet();
    }
    return 0;
}
