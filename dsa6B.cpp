
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int id;
    Node *left, *right;
};

Node* insert(Node* root, int id) {
    if (root == NULL) {
        Node* t = new Node;
        t->id = id;
        t->left = t->right = NULL;
        return t;
    }

    if (id < root->id)
        root->left = insert(root->left, id);
    else if (id > root->id)
        root->right = insert(root->right, id);

    return root;
}

void display(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* t = q.front();
        q.pop();

        cout << t->id << " ";

        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
    }
    cout << endl;
}

Node* mirror(Node* root) {
    if (!root) return NULL;

    Node* t = new Node;
    t->id = root->id;
    t->left = mirror(root->right);
    t->right = mirror(root->left);

    return t;
}

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void leafNodes(Node* root) {
    if (!root) return;

    if (!root->left && !root->right) {
        cout << root->id << " ";
        return;
    }

    leafNodes(root->left);
    leafNodes(root->right);
}

int main() {
    Node* root = NULL;
    int n, id;

    cout << "Enter number of employees: ";
    cin >> n;

    cout << "Enter employee IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> id;
        root = insert(root, id);
    }

    cout << "Original Employee BST: ";
    display(root);

    Node* newTree = mirror(root);
    cout << "New Employee Tree: ";
    display(newTree);

    cout << "Height of Tree: " << height(root) << endl;

    cout << "Leaf Employee IDs: ";
    leafNodes(root);

    return 0;
}
