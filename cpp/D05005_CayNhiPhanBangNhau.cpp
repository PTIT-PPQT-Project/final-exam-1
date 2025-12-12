#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int leftNode1[10001];
int rightNode1[10001];
bool isChild1[10001];
set<int> allNodes1;

int leftNode2[10001];
int rightNode2[10001];
bool isChild2[10001];
set<int> allNodes2;

int docCay(int N, int leftNode[], int rightNode[], bool isChild[], set<int>& allNodes) {
    memset(leftNode, 0, sizeof(int) * 10001);
    memset(rightNode, 0, sizeof(int) * 10001);
    memset(isChild, false, sizeof(bool) * 10001);
    allNodes.clear();

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

    if (N == 0) return 0;

    int root = 0;
    for (int u : allNodes) {
        if (!isChild[u]) {
            root = u;
            break;
        }
    }
    return root;
}

bool isSameTree(int u1, int u2) {
    if (u1 == 0 && u2 == 0) {
        return true;
    }
    if (u1 == 0 || u2 == 0) {
        return false;
    }
    if (u1 != u2) {
        return false;
    }
    return isSameTree(leftNode1[u1], leftNode2[u2]) && 
           isSameTree(rightNode1[u1], rightNode2[u2]);
}

void giaiQuyet() {
    int N1;
    cin >> N1;
    int root1 = docCay(N1, leftNode1, rightNode1, isChild1, allNodes1);
    
    int N2;
    cin >> N2;
    int root2 = docCay(N2, leftNode2, rightNode2, isChild2, allNodes2);

    if (isSameTree(root1, root2)) {
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
