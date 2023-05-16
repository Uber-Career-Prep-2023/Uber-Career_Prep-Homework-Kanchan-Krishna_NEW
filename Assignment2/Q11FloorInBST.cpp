#include <bits/stdc++.h>
using namespace std;
//Given a target numeric value and a binary search tree, return the floor(greatest element less than or equal to the target) in the BST.

/*
Time Taken: 20 min
Space Complexity: O(n) where N is the # of nodes used 
Technique Used: General Tree Recursion
*/

class Node {
    public:
        Node* left;
        Node* right;
        int data;
    private:
        Node* root;
};

Node* createBSTNode(int val) {
    Node* new_node = new Node();
    new_node->data = val;
    new_node->left = nullptr; 
    new_node->right = nullptr;
    return new_node;
}

Node* insertBSTNode(Node* node, int val) {
    if (node == nullptr) {
        return createBSTNode(val);
    }
    if (val < node->data) {
        node->left = insertBSTNode(node->left, val);
    } else if (val > node->data) {
        node->right = insertBSTNode(node->right, val);
    }
    return node;
}

//Time Complexity: O(h) where h is the height of a tree 

int floorInBST(Node* root, int target) {
    if (root == nullptr) {
        return -1;
    }
    if (root->data == target) {
        return target;
    } else if (root->data < target) {
        int k = floorInBST(root->right, target);
        if (k == -1) {
            return root->key;
        } else {
            return k;
        }
        else if (root->data > target) {
            return floorInBST(root->left, target);
        }
    }
}

int main() {
    int target = 6;
    Node* root = insert(root, 9);
    insert(root, 3);
    insert(root, 11);
    insert(root, 6);
    insert(root, 4);
    insert(root, 5);
    insert(root, 18);
    insert(root, 1);
    insert(root, 0);
    cout << floorInBST(root, target) << endl;
}