#include <bits/stdc++.h>
using namespace std;

/*
Time Taken: 10 min + 10 min for fixes 
Time & Space Complexity: O(n) where N is the # of nodes used
Technique Used: Tree Recursion
*/

struct Node {
    Node* left;
    Node* right;
    int data;
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    cout << root->data << endl;
    printTree(root->right);
}

Node* copyTree(Node* root) {
    if (!root) {
        return nullptr;
    }
    Node* new_copy = new Node(root->data);
    new_copy->left = copyTree(root->left);
    new_copy->right = copyTree(root->right);
    return new_copy;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(5);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    root->right->left = new Node(4);
    root->right->right = new Node(9);
    Node* copy_tree = copyTree(root);
    printTree(copy_tree);
}
