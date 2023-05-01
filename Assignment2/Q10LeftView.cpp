#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left; 
        Node* right;
};

void leftViewHelper(Node* root, int level, int* max_level) {
    if (root == NULL) {
        return;
    }
    if (*max_level < level) {
        cout << root->data << "\t";
        *max_level = level;
    }
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}

void leftView(Node* root) {
    int max_level = 0;
    leftViewHelper(root, 1, &max_level);
}
