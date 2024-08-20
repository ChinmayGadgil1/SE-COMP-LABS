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

    // Function to copy the tree
    BST copyTree()
    {
        BST newTree;
        newTree.root = copyNodes(root);
        return newTree;
    }

    Node* copyNodes(Node* root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        Node* newNode = new Node(root->data);
        newNode->left = copyNodes(root->left);
        newNode->right = copyNodes(root->right);
        return newNode;
    }

    // Function to compare two trees
    bool compareTrees(const BST& other)
    {
        return compareNodes(this->root, other.root);
    }

    bool compareNodes(Node* root1, Node* root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }
        if (root1 == NULL || root2 == NULL)
        {
            return false;
        }
        return (root1->data == root2->data) &&
               compareNodes(root1->left, root2->left) &&
               compareNodes(root1->right, root2->right);
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
        cout << "3. Copy Tree\n";
        cout << "4. Compare Trees\n";
        cout << "5. Exit\n";
        cout << "Your choice=> ";
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
            cout << "\n";
        }
        else if (choice == 3)
        {
            BST copiedTree = bst.copyTree();
            cout << "Copied tree :\n";
            copiedTree.inorderTraversal();
            cout << "\n";
        }
        else if (choice == 4)
        {
            BST otherTree;
            int numNodes, value;
            cout << "Enter the number of nodes in the other tree:\n";
            cin >> numNodes;
            for (int i = 0; i < numNodes; ++i)
            {
                cout << "Enter value for node " << i + 1 << ":\n";
                cin >> value;
                otherTree.insert(value);
            }
            if (bst.compareTrees(otherTree))
            {
                cout << "The binary trees are identical.\n";
            }
            else
            {
                cout << "The binary trees are not identical.\n";
            }
        }
        else if (choice == 5)
        {
            break;
        }
    }

    return 0;
}