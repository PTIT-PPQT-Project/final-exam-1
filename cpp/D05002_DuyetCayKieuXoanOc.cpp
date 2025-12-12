#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>

using namespace std;

int leftNode[10001];
int rightNode[10001];
bool isChild[10001];
set<int> allNodes;

void spiralOrder(int root) {
    if (root == 0) {
        return;
    }

    stack<int> s1;
    stack<int> s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            int u = s1.top();
            s1.pop();
            cout << u << " ";

            if (rightNode[u] != 0) {
                s2.push(rightNode[u]);
            }
            if (leftNode[u] != 0) {
                s2.push(leftNode[u]);
            }
        }

        while (!s2.empty()) {
            int u = s2.top();
            s2.pop();
            cout << u << " ";

            if (leftNode[u] != 0) {
                s1.push(leftNode[u]);
            }
            if (rightNode[u] != 0) {
                s1.push(rightNode[u]);
            }
        }
    }
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
    for (int u : allNodes) {
        if (!isChild[u]) {
            root = u;
            break;
        }
    }

    spiralOrder(root);
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
