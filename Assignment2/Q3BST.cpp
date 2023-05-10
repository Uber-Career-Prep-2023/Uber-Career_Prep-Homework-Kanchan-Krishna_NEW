#include "BST.hpp"
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
Time Taken: 30 min
Space Complexity: O(n) where N is the # of nodes used
Technique Used: BST Creation
*/

//Time Complexity: Worst case O(N) where N is the height of the tree
int BST::min() {
    if (root == nullptr) {
        return -1; 
    }
    Node* curr = root;
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr->val;
}

// Time Complexity: Worst case O(N) where N is the height of the tree
int BST::max() {
    if (root == nullptr) {
        return -1;
    }
    Node *curr = root;
    while (curr->right != nullptr) {
        curr = curr->right;
    }
    return curr->val;
}

// Time Complexity: Worst case O(N) where N is the height of the tree if you are dealing with an unbalanced one
bool BST::contains(int search_for) {
    Node* curr = root;
    while (curr != nullptr) {
        if (curr->val == search_for) {
            return true;
        } else if (curr->val < search_for) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return false;
}

//Time Complexity: O(h) where h is the height of a tree
BST::Node* BST::insertBSTNode(Node *node, int val) {
    if (node == nullptr) {
        return nullptr; 
    }
    if (val < node->data) {
        node->left = insertBSTNode(node->left, val);
    } else if (val > node->data) {
        node->right = insertBSTNode(node->right, val);
    }
    return node;
}

// Time Complexity: Worst case O(N) where N is the height of the tree
BST::Node* BST::deleteNode(Node* root, int delete_this) {
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