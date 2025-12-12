#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void giaiBaiToan() {
    int n;
    cin >> n;
    
    vector<int> gia(n);
    for (int i = 0; i < n; i++) {
        cin >> gia[i];
    }
    
    vector<int> nhip(n);
    stack<int> nganXep;
    
    for (int i = 0; i < n; i++) {
        while (!nganXep.empty() && gia[nganXep.top()] <= gia[i]) {
            nganXep.pop();
        }
        
        if (nganXep.empty()) {
            nhip[i] = i + 1;
        } else {
            nhip[i] = i - nganXep.top();
        }
        
        nganXep.push(i);
    }
    
    for (int i = 0; i < n; i++) {
        cout << nhip[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int soTest;
    cin >> soTest;
    
    while (soTest--) {
        giaiBaiToan();
    }
    
    return 0;
}
