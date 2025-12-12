#include <iostream>
#include <vector>

using namespace std;

void inMang(const vector<int>& a, int buoc, int soLuong) {
    cout << "Buoc " << buoc << ":";
    for (int i = 0; i <= soLuong; ++i) {
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

    for (int i = 0; i < n; ++i) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        
        inMang(a, i, i);
    }

    return 0;
}
