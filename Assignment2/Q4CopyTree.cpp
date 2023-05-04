#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void printTree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " " << endl;
    inorder(root->right);
}

Node *copyTree(Node *root)
{
    if (!root)
    {
        return nullptr;
    }
    Node *new_copy = new Node(root->data);
    new_copy->left = cloneBinaryTree(root->left);
    new_copy->right = cloneBinaryTree(root->right);
    return new_copy;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node *copy_tree = copyTree(root);
    printTree(clone);
    return 0;
}