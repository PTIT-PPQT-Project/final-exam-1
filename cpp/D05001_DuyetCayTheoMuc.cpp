#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

int leftNode[10001];
int rightNode[10001];
bool isChild[10001];
set<int> parentNodes;

void levelOrder(int root) {
    if (root == 0) {
        return;
    }
    queue<int> q;
    q.push(root);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        if (leftNode[u] != 0) {
            q.push(leftNode[u]);
        }
        if (rightNode[u] != 0) {
            q.push(rightNode[u]);
        }
    }
}

void giaiQuyet() {
    memset(leftNode, 0, sizeof(leftNode));
    memset(rightNode, 0, sizeof(rightNode));
    memset(isChild, false, sizeof(isChild));
    parentNodes.clear();

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int u, v;
        char x;
        cin >> u >> v >> x;

        parentNodes.insert(u);
        isChild[v] = true;

        if (x == 'L') {
            leftNode[u] = v;
        } else {
            rightNode[u] = v;
        }
    }

    int root = 0;
    for (int u : parentNodes) {
        if (!isChild[u]) {
            root = u;
            break;
        }
    }

    levelOrder(root);
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
