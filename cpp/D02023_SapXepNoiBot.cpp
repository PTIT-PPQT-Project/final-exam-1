#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void inMang(const vector<int>& a, int buoc) {
    cout << "Buoc " << buoc << ":";
    for (int i = 0; i < a.size(); ++i) {
        cout << " " << a[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    bool daDoiCho;
    for (int i = 0; i < n - 1; ++i) {
        daDoiCho = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                daDoiCho = true;
            }
        }
        
        if (!daDoiCho) {
            break;
        }
        
        inMang(a, i + 1);
    }

    return 0;
}
