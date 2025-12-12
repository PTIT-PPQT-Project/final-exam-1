#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> nodeValues;
int valueIndex;

void collectValuesInOrder(Node* u) {
    if (u == nullptr) {
        return;
    }
    collectValuesInOrder(u->left);
    nodeValues.push_back(u->data);
    collectValuesInOrder(u->right);
}

void replaceValuesInOrder(Node* u) {
    if (u == nullptr) {
        return;
    }
    replaceValuesInOrder(u->left);
    u->data = nodeValues[valueIndex++];
    replaceValuesInOrder(u->right);
}

void printInOrder(Node* u) {
    if (u == nullptr) {
        return;
    }
    printInOrder(u->left);
    cout << u->data << " ";
    printInOrder(u->right);
}

void giaiQuyet() {
    int N;
    cin >> N;
    
    map<int, Node*> nodes;
    set<int> isChild;
    nodeValues.clear();
    valueIndex = 0;

    for (int i = 0; i < N; ++i) {
        int u, v;
        char x;
        cin >> u >> v >> x;

        isChild.insert(v);
        Node* parent = nullptr;
        if (nodes.find(u) == nodes.end()) {
            parent = new Node(u);
            nodes[u] = parent;
        } else {
            parent = nodes[u];
        }

        Node* child = nullptr;
        if (nodes.find(v) == nodes.end()) {
            child = new Node(v);
            nodes[v] = child;
        } else {
            child = nodes[v];
        }

        if (x == 'L') {
            parent->left = child;
        } else {
            parent->right = child;
        }
    }

    Node* root = nullptr;
    if (N > 0) {
        for (auto const& pair : nodes) {
            if (isChild.find(pair.first) == isChild.end()) {
                root = pair.second;
                break;
            }
        }
    }

    collectValuesInOrder(root);
    
    sort(nodeValues.begin(), nodeValues.end());
    
    replaceValuesInOrder(root);
    
    printInOrder(root);
    cout << "\n";
    
    for (auto const& pair : nodes) {
        delete pair.second;
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
