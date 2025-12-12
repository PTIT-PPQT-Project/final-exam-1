#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[1001];
int N;

int timDoSau(int start, int end) {
    if (start > end) {
        return -1;
    }

    int rootVal = A[start];

    int i = start + 1;
    while (i <= end && A[i] < rootVal) {
        i++;
    }

    int doSauTrai = timDoSau(start + 1, i - 1);
    int doSauPhai = timDoSau(i, end);

    return 1 + max(doSauTrai, doSauPhai);
}

void giaiQuyet() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << timDoSau(0, N - 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        giaiQuyet();
    }
    return 0;
}
