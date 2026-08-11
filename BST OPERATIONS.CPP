#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Find minimum node
Node* findMin(Node* root)
{
    Node* current = root;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* root, int value)
{
    if (root == NULL)
    {
        return root;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }

    // Search in right subtree
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }

  
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        else if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node* temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);

        cout << root->data << " ";

        inorder(root->right);
    }
}

int main()
{
    Node* root = NULL;

    int n, value, deleteValue;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }
    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << "\nEnter element to delete: ";
    cin >> deleteValue;
    root = deleteNode(root, deleteValue);
    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}