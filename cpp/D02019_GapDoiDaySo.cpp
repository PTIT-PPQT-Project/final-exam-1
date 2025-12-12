#include <iostream>

using namespace std;

int timSo(int n, long long k) {
    long long giua = 1LL << (n - 1);

    if (k == giua) {
        return n;
    }
    if (k < giua) {
        return timSo(n - 1, k);
    }
    return timSo(n - 1, k - giua);
}

void giaiQuyet() {
    int n;
    long long k;
    cin >> n >> k;
    cout << timSo(n, k) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        giaiQuyet();
    }
    return 0;
}
