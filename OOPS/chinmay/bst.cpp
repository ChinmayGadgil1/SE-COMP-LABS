#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = NULL;
    }

    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    Node *insertRecursive(Node *root, int value)
    {
        if (root == NULL)
        {
            return new Node(value);
        }

        if (value < root->data)
        {
            root->left = insertRecursive(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    void inorderTraversal()
    {
        inorder(root);
    }

    void inorder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main()
{
    BST bst;

    int choice;

    while (true)
    {
        cout << "What would you like to do\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Exit\n";
        cout<<"Your choice=> ";
        cin >> choice;
        if (choice == 1)
        {
            int value;
            cout << "Enter the value you want to insert\n";
            cin >> value;
            bst.insert(value);
        }
        else if (choice == 2)
        {
            cout << "\n";
            bst.inorderTraversal();
            cout << "\n";
        }
        else if (choice == 3)
        {
            break;
        }
    }

    return 0;
}