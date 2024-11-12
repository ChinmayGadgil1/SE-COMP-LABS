#include <iostream>
#include <vector>
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
    ~Node()
    {
        delete left;
        delete right;
    }
};

class BST
{
private:
    Node *root;
    int size;
public:
    BST()
    {
        root = NULL;
        size=0;
    }

    void insert(int value)
    {
        root = insertNode(root, value);
        size++;
    }

    Node *insertNode(Node *root, int value)
    {
        if (root == NULL)
        {
            return new Node(value);
        }

        if (value < root->data)
        {
            root->left = insertNode(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insertNode(root->right, value);
        }

        return root;
    }

    void inorderTraversal() const
    {
        inorder(root);
    }

    void inorder(Node *root) const
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->data <<" ";
            inorder(root->right);
        }
    }

    BST copyTree() const
    {
        BST newTree;
        newTree.root = copyNodes(root);
        return newTree;
    }

    Node* copyNodes(Node* root) const
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

    bool operator ==(BST& other) 
    {
        if(size!= other.size) return false;
        vector<int> a,b;
        getInorder(this->root, a);
        getInorder(other.root,b );
        // BST* otherptr=&other;

    //    return compareTree(this,otherptr);

    return a==b;  
        
    }

    // friend bool compareTree(BST* first,BST* second){
    //     if (first==NULL || second ==NULL)
    //     {
    //         return false;
    //     }
    //     if(first->root->data!=second->root->data) return false;

    // }

    void getInorder(Node* root, vector<int>& inorder) 
    {
        if (root != NULL)
        {
            getInorder(root->left, inorder);
            inorder.push_back(root->data);
            getInorder(root->right, inorder);
        }
    }
};

int main()
{
    BST bst1;

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
            bst1.insert(value);
        }
        else if (choice == 2)
        {
            cout << "\n";
            bst1.inorderTraversal();
            cout << "\n";
        }
        else if (choice == 3)
        {
            BST copiedTree = bst1.copyTree();
            cout << "Copied tree (inorder traversal):\n";
            copiedTree.inorderTraversal();
            cout << "\n\n";
        }
        else if (choice == 4)
        {
            BST bst2;
            int numNodes, value;
            cout << "Enter the number of nodes in the other tree:\n";
            cin >> numNodes;
            for (int i = 0; i < numNodes; ++i)
            {
                cout << "Enter value for node " << i + 1 << ":\n";
                cin >> value;
                bst2.insert(value);
            }
            if (bst1==bst2)
            {
                cout << "\nThe binary trees are identical.\n\n";
            }
            else
            {
                cout << "\nThe binary trees are not identical.\n\n";
            }
        }
        else if (choice == 5)
        {
            break;
        }
    }

    return 0;
}