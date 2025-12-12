#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

int leftNode[10001];
int rightNode[10001];
bool isChild[10001];
set<int> allNodes;

void giaiQuyet() {
    memset(leftNode, 0, sizeof(leftNode));
    memset(rightNode, 0, sizeof(rightNode));
    memset(isChild, false, sizeof(isChild));
    allNodes.clear();

    int N;
    cin >> N;
    if (N == 0) {
        cout << "Yes\n";
        return;
    }

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
    for (int u : allNodes) {
        if (!isChild[u]) {
            root = u;
            break;
        }
    }

    if (root == 0) {
        cout << "Yes\n";
        return;
    }

    bool isPerfect = true;
    int firstLeafDepth = -1;
    queue<pair<int, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int u = q.front().first;
        int depth = q.front().second;
        q.pop();

        bool hasLeft = (leftNode[u] != 0);
        bool hasRight = (rightNode[u] != 0);

        if (!hasLeft && !hasRight) {
            if (firstLeafDepth == -1) {
                firstLeafDepth = depth;
            } else if (depth != firstLeafDepth) {
                isPerfect = false;
                break;
            }
        } else if (hasLeft && hasRight) {
            if (firstLeafDepth != -1) {
                isPerfect = false;
                break;
            }
            q.push({leftNode[u], depth + 1});
            q.push({rightNode[u], depth + 1});
        } else {
            isPerfect = false;
            break;
        }
    }

    if (isPerfect) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
