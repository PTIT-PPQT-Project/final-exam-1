#include <iostream>

using namespace std;

int n;
long long dem = 0;
char xau[15];

void inXau() {
    cout << dem << ": ";
    for (int i = 1; i <= n; i++) {
        cout << xau[i];
    }
    cout << endl;
}

void lietKe(int i) {
    for (char kyTu = 'A'; kyTu <= 'C'; kyTu++) {
        xau[i] = kyTu;
        
        if (i == n) {
            dem++;
            if (dem % 2 != 0) {
                inXau();
            }
        } else {
            lietKe(i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    if (n <= 2 || n >= 12) {
        return 0; 
    }

    lietKe(1);

    return 0;
}
