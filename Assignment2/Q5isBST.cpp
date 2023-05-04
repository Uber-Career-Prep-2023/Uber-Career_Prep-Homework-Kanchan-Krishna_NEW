#include <bits/stdc++.h>
class Node {
    public:
        Node* left;
        Node* right;
        int data;
        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
    private:
        Node* root;
};

// TC & SC: O(N) where N is the # of nodes in the tree esp when you have a skewed tree like 4-3-2-1 to the left and recursive stack is going to store all these values
class Solution { // top down dfs
public:
    bool isValidBST(Node* root) {
        return validHelper(root, nullptr, nullptr); //-inf and +inf
    }
    bool validHelper(Node* root, Node* low, Node* high) {
        if (root == nullptr) {
            return true; // empty tree is a valid BST
        }
        if ((low != nullptr && low->val >= root->val) || (high != nullptr && high->val <= root->val)) {
            return false;
        }
        return valid(root->left, low, root) && valid(root->right, root, high);
        // moving on to left subtree: lower limit is same; high changes to root val
        // moving on to right subtree: high limit is same; low changes to prev root
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(1);
    cout << isValidBST(root) << endl;
}