#include <iostream>
#include <string>
#include <stack>

using namespace std;

void giaiQuyet() {
    string s;
    cin >> s;
    
    stack<char> st;
    
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                st.push(c);
            }
        }
    }
    
    int soNgoacDongThua = 0; 
    int soNgoacMoThua = 0;  
    
    while (!st.empty()) {
        if (st.top() == ')') {
            soNgoacDongThua++;
        } else {
            soNgoacMoThua++;
        }
        st.pop();
    }
    
    int soPhepDoi = 0;
    
    soPhepDoi += soNgoacDongThua / 2;
    soPhepDoi += soNgoacMoThua / 2;
    
    if (soNgoacDongThua % 2 == 1) {
        soPhepDoi += 2; 
    }
    
    cout << soPhepDoi << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        giaiQuyet();
    }
    return 0;
}
