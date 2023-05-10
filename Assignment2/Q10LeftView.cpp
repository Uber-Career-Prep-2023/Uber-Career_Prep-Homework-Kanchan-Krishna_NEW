#include <bits/stdc++.h>
using namespace std;
// Given a binary tree, create an array of the left view (leftmost elements in each level) of the tree.

/*
Time Taken: 30 min
Space Complexity: O(1) if you do not count the output
Technique Used: Inorder Tree Traversal 
*/

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
        Node *root;
};

// Time Complexity: O(N) where N is the number of nodes in the binary tree 
void leftViewHelper(Node* root, int level, int max_level, vector<int>& v) {
    if (root == nullptr) {
        return;
    }
    if (max_level < level) {
        v.push_back(root->data);
        max_level = level;
    }
    leftViewHelper(root->left, level + 1, max_level);
    leftViewHelper(root->right, level + 1, max_level);
}

vector<int> leftView(Node* root) {
    vector<int> v; 
    int max_level = 0;
    leftViewHelper(root, 1, max_level, v);
    return v; 
}

void printTree(Node *root) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        cout << root->data << endl;
        return;
    }
    if (root->left) {
        printTree(root->left);
    }
    if (root->right) {
        printTree(root->right);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(6);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(8);
    root->right->left = new Node(19);
    root->right->right = new Node(3);
    printTree(root);
    vector<int> v = leftView(root);
    cout << "Printing left view now" << endl; 
    for (auto ele : v) {
        cout << ele << endl;
    }
}
