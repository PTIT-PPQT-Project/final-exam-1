#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void rnlTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    rnlTraversal(root->right);
    cout << root->data << " ";
    rnlTraversal(root->left);
}

Node* buildTree(const vector<string>& tokens) {
    if (tokens.empty() || tokens[0] == "N") {
        return nullptr;
    }

    Node* root = new Node(stoi(tokens[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < tokens.size()) {
        Node* current = q.front();
        q.pop();

        if (i < tokens.size() && tokens[i] != "N") {
            current->left = new Node(stoi(tokens[i]));
            q.push(current->left);
        }
        i++;

        if (i < tokens.size() && tokens[i] != "N") {
            current->right = new Node(stoi(tokens[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}

void freeTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void giaiQuyet() {
    string line;
    getline(cin, line);
    
    stringstream ss(line);
    string token;
    vector<string> tokens;
    while (ss >> token) {
        tokens.push_back(token);
    }

    Node* root = buildTree(tokens);
    
    rnlTraversal(root);
    
    cout << "\n";
    
    freeTree(root);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        giaiQuyet();
    }
    return 0;
}
