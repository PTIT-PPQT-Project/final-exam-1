#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void timPreorder(const vector<int>& A, int start, int end) {
    if (start > end) {
        return;
    }

    int mid = (start + end) / 2;
    
    cout << A[mid] << " ";
    
    timPreorder(A, start, mid - 1);
    
    timPreorder(A, mid + 1, end);
}

void giaiQuyet() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    timPreorder(A, 0, N - 1);
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
