#include <bits/stdc++.h>
using namespace std; 
/*
Time Taken: 20 min + 10 min for fixes 
Time & Space Complexity: O(N) where N is the # of nodes in the tree esp when you have a skewed tree 
like 4-3-2-1 to the left and recursive stack is going to store all these values
Technique Used: Tree Recursion
*/

struct Node {
    Node* left;
    Node* right;
    int val;
    Node(int data) {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

//Assumption: there are no duplicate values 

bool validHelper(Node* root, Node* low, Node* high) {
    if (root == nullptr) {
        return true; // empty tree is a valid BST
    }
    if ((low != nullptr && low->val >= root->val) || (high != nullptr && high->val <= root->val)) {
        return false;
    }
    return validHelper(root->left, low, root) && validHelper(root->right, root, high);
    // moving on to left subtree: lower limit is same; high changes to root val
    // moving on to right subtree: high limit is same; low changes to prev root
}

bool isValidBST(Node* root) {
    return validHelper(root, nullptr, nullptr); //-inf and +inf
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(1);
    bool result = isValidBST(root); 
    if (result == 0) {
        cout << "Not a valid BST";
    } else {
        cout << "Valid BST";
    }
}