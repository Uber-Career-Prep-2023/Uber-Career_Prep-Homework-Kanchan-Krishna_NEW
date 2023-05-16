#include "BST.hpp"
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
Time Taken: 30 min
Space Complexity: O(n) where N is the # of nodes used
Technique Used: BST Creation
*/

// Time Complexity: Worst case O(N) where N is the height of the tree
int BST::min()
{
    if (root == nullptr)
    {
        return -1;
    }
    Node *curr = root;
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr->val;
}

// Time Complexity: Worst case O(N) where N is the height of the tree
int BST::max()
{
    if (root == nullptr)
    {
        return -1;
    }
    Node *curr = root;
    while (curr->right != nullptr)
    {
        curr = curr->right;
    }
    return curr->val;
}

// Time Complexity: Worst case O(N) where N is the height of the tree if you are dealing with an unbalanced one
bool BST::contains(int &search_for)
{
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->val == search_for)
        {
            return true;
        }
        else if (search_for < curr->val)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    return false;
}

// Time Complexity: O(h) where h is the height of a tree
BST::Node *BST::insertBSTNode(Node *node, int val)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (val < node->data)
    {
        node->left = insertBSTNode(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = insertBSTNode(node->right, val);
    }
    return node;
}

// Time Complexity: Worst case O(N) where N is the height of the tree
/*BST::Node* BST::deleteNode(Node* root, int delete_this) {
    if (root == nullptr) {
        return nullptr;
    } else {
        if (delete_this == root->val) {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* min;
                Node* current = root->right;
                while (current->left != nullptr)
                {
                    current = current->left;
                }
                min = current;
                root->val = min->val;
                root->right = deleteNode(root->right, min->val);
            }
        } else {
            if (delete_this < root->val) {
                root->left = deleteNode(root->left, delete_this);
            } else if (delete_this > root->val) {
                root->right = deleteNode(root->right, delete_this);
            }
        }
        return root;
    }
}*/

// trying again
/*
    - if you delete a leaf node, no problem just delete it because will not affect the rest of the tree
    - if you delete a node with 2 children, choose the inorder successor or the inorder predecessor
    - if you delete a node with one child (left or right), you can delete the node after replacing it with its left or right child
*/

int BST::findInorderSuccessor(Node* root)
{
    root = root->right;
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root->val;
}

int BST::findInorderPredecessor(Node* root)
{
    root = root->left;
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root->val;
}

BST::Node* BST::deleteNode(Node* root, int& delete_this) {
    if (root == nullptr) {
        return nullptr;
    }
    if (delete_this > root->val) {
        root->right = deleteNode(root->right, delete_this);
    } else if (delete_this < root->val)
        root->left = deleteNode(root->left, delete_this);
    else {
        if (root->left == nullptr && root->right == nullptr) { //leaf node case 
            root = nullptr;
        } else if (root->right != nullptr) {
            root->val = findInorderSuccessor(root);
            root->right = deleteNode(root->right, root->val);
        } else {
            root->val = findInorderPredecessor(root);
            root->left = deleteNode(root->left, root->val);
        }
    }
    return root;
}

void BST::printTree(Node *root)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        cout << root->data << endl;
        return;
    }
    if (root->left)
    {
        printTree(root->left);
    }
    if (root->right)
    {
        printTree(root->right);
    }
}