#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int leftNode[10001];
int rightNode[10001];
bool isChild[10001];
set<int> allNodes;

int firstLeafDepth;
bool allSameDepth;

void findLeafDepth(int u, int currentDepth) {
    if (u == 0 || !allSameDepth) {
        return;
    }

    bool isLeaf = true;
    if (leftNode[u] != 0) {
        isLeaf = false;
        findLeafDepth(leftNode[u], currentDepth + 1);
    }
    
    if (rightNode[u] != 0) {
        isLeaf = false;
        findLeafDepth(rightNode[u], currentDepth + 1);
    }

    if (isLeaf) {
        if (firstLeafDepth == -1) {
            firstLeafDepth = currentDepth;
        } else if (currentDepth != firstLeafDepth) {
            allSameDepth = false;
        }
    }
}

void giaiQuyet() {
    memset(leftNode, 0, sizeof(leftNode));
    memset(rightNode, 0, sizeof(rightNode));
    memset(isChild, false, sizeof(isChild));
    allNodes.clear();
    
    firstLeafDepth = -1;
    allSameDepth = true;

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
    for (int u : allNodes) {
        if (!isChild[u]) {
            root = u;
            break;
        }
    }

    if (root != 0) {
        findLeafDepth(root, 0);
    }

    cout << allSameDepth << "\n";
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
