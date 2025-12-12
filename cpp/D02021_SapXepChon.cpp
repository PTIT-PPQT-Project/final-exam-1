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

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        
        swap(a[i], a[min_idx]);
        
        inMang(a, i + 1);
    }

    return 0;
}
