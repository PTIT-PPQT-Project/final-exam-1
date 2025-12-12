#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

void giaiQuyet() {
    int n;
    cin >> n;
    
    queue<string> hangDoi;
    hangDoi.push("1");
    
    for (int i = 0; i < n; ++i) {
        string soNhiPhan = hangDoi.front();
        hangDoi.pop();
        
        cout << soNhiPhan << " ";
        
        hangDoi.push(soNhiPhan + "0");
        hangDoi.push(soNhiPhan + "1");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int soBoTest;
    cin >> soBoTest;
    while (soBoTest--) {
        giaiQuyet();
    }
    return 0;
}
