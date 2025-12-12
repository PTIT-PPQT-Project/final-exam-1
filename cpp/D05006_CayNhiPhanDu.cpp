#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int leftNode[10001];
int rightNode[10001];
bool isChild[10001];
set<int> allNodes;

bool isFull(int u) {
    if (u == 0) {
        return true;
    }

    if (leftNode[u] == 0 && rightNode[u] == 0) {
        return true;
    }

    if (leftNode[u] != 0 && rightNode[u] != 0) {
        return isFull(leftNode[u]) && isFull(rightNode[u]);
    }

    return false;
}

void giaiQuyet() {
    memset(leftNode, 0, sizeof(leftNode));
    memset(rightNode, 0, sizeof(rightNode));
    memset(isChild, false, sizeof(isChild));
    allNodes.clear();

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int u, v;
        char x;
        cin >> u >> v >> x;

        allNodes.insert(u);
        allNodes.insert(v);
        isChild[v] = true;

        if (x == 'L') {
            leftNode[u] = v;
        } else {
            rightNode[u] = v;
        }
    }

    int root = 0;
    if (N == 0) {
        cout << "1\n";
        return;
    }

    for (int u : allNodes) {
        if (!isChild[u]) {
            root = u;
            break;
        }
    }

    if (isFull(root)) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
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
