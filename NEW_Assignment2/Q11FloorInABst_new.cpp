#include <bits/stdc++.h>
using namespace std;

/*
Time Taken: 10 min + 15 min for fixes 
Time Complexity: O(n) where N is the # of nodes used; Space Complexity: O(1)
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

int FloorInBST(Node* root, int k) {
    int floor = -1;
    if (root == nullptr) {
        return floor;
    }
    if (root->data == k) {
        return root->data;
    }
    Node* curr = root;
    while (curr != nullptr) {
        if (curr->data == k) {
            return curr->data;
        } else if (curr->data > k) {
            curr = curr->left;
        }
        else {
            floor = curr->data;
            curr = curr->right;
        }
    }
    return floor;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(5);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    root->right->left = new Node(4);
    root->right->right = new Node(9);
    cout << FloorInBST(root, 5);
}