
#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int rollNo;
    Node *left;
    Node *right;

    Node(int value)
    {
        rollNo = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node *root;

    Node* insert(Node *root, int value)
    {
        if (root == NULL)
        {
            return new Node(value);
        }

        if (value < root->rollNo)
        {
            root->left = insert(root->left, value);
        }
        else if (value > root->rollNo)
        {
            root->right = insert(root->right, value);
        }
        else
        {
            cout << "Duplicate value not inserted!\n";
        }

        return root;
    }

public:
    BST()
    {
        root = NULL;
    }

    void insertValue(int value)
    {
        root = insert(root, value);
    }

    // Non-recursive Inorder Traversal
    void inorder()
    {
        stack<Node*> s;
        Node *current = root;

        cout << "\nInorder Traversal: ";

        while (current != NULL || !s.empty())
        {
            while (current != NULL)
            {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();

            cout << current->rollNo << " ";

            current = current->right;
        }

        cout << endl;
    }

    // Non-recursive Preorder Traversal
    void preorder()
    {
        if (root == NULL)
        {
            return;
        }

        stack<Node*> s;
        s.push(root);

        cout << "\nPreorder Traversal: ";

        while (!s.empty())
        {
            Node *current = s.top();
            s.pop();

            cout << current->rollNo << " ";

            // Push right first because stack follows LIFO
            if (current->right != NULL)
            {
                s.push(current->right);
            }

            if (current->left != NULL)
            {
                s.push(current->left);
            }
        }

        cout << endl;
    }
};

int main()
{
    BST tree;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        tree.insertValue(value);
    }

    tree.inorder();
    tree.preorder();

    return 0;
}
