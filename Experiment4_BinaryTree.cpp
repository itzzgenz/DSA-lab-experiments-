
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BinaryTree
{
private:
    Node *root;

    Node* createTree()
    {
        int value;

        cout << "Enter node value (-1 for no node): ";
        cin >> value;

        if (value == -1)
        {
            return NULL;
        }

        Node *newNode = new Node;
        newNode->data = value;

        cout << "Enter Left Child of " << value << ": ";
        newNode->left = createTree();

        cout << "Enter Right Child of " << value << ": ";
        newNode->right = createTree();

        return newNode;
    }

    void inorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree()
    {
        root = NULL;
    }

    void build()
    {
        cout << "\nCreate Binary Tree:\n";
        root = createTree();
        cout << "\nBinary Tree Created Successfully!\n";
    }

    void displayInorder()
    {
        cout << "\nInorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder()
    {
        cout << "\nPreorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder()
    {
        cout << "\nPostorder Traversal: ";
        postorder(root);
        cout << endl;
    }
};

int main()
{
    BinaryTree library;
    int choice;

    do
    {
        cout << "\n===== LIBRARY CATALOG =====\n";
        cout << "1. Construct Binary Tree\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                library.build();
                break;

            case 2:
                library.displayInorder();
                break;

            case 3:
                library.displayPreorder();
                break;

            case 4:
                library.displayPostorder();
                break;

            case 5:
                cout << "\nProgram ended.\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
