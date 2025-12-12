#include <iostream>
#include <vector>

using namespace std;

int A[1001];
int N;

void timPostorder(int start, int end) {
    if (start > end) {
        return;
    }

    int rootVal = A[start];

    int i = start + 1;
    while (i <= end && A[i] < rootVal) {
        i++;
    }

    timPostorder(start + 1, i - 1);

    timPostorder(i, end);

    cout << rootVal << " ";
}

void giaiQuyet() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    timPostorder(0, N - 1);
    cout << "\n";
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
