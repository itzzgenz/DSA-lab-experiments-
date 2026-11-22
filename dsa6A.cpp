#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

Node* insert(Node* root, int x) {
    if (root == NULL) return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}
void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* t = q.front();
        q.pop();
        cout << t->data << " ";

        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
    }
    cout << endl;
}
Node* mirror(Node* root) {
    if (!root) return NULL;

    Node* t = createNode(root->data);
    t->left = mirror(root->right);
    t->right = mirror(root->left);
    return t;
}
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
void leaves(Node* root) {
    if (!root) return;

    if (!root->left && !root->right) {
        cout << root->data << " ";
        return;
    }

    leaves(root->left);
    leaves(root->right);
}
int main() {
    Node* root = NULL;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Original BST: ";
    levelOrder(root);

    Node* newTree = mirror(root);
    cout << "New Tree: ";
    levelOrder(newTree);

    cout << "Height: " << height(root) << endl;

    cout << "Leaf Nodes: ";
    leaves(root);

    return 0;
}
