#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
    public:
        BST() {
            root = nullptr;
        }
        // Time Complexity: Worst case O(N) where N is the height of the tree
        int min() {
            if (root == nullptr) {
                return -1; //assuming that is not already a value in the BST 
            }
            Node* curr = root;
            while (curr->left != nullptr) {
                curr = curr->left;
            }
            return curr->data;
        }
        // Time Complexity: Worst case O(N) where N is the height of the tree
        int max() {
            if (root == nullptr) {
                return -1; //assuming that is not already a value in the BST
            }
            Node* curr = root;
            while (curr->right != nullptr) {
                curr = curr->right;
            }
            return curr->data;
        }
        // Time Complexity: Worst case O(N) where N is the height of the tree
        void printTree(Node* root) { //perform inorder traversal 
            if (root == nullptr) {
                return;
            }
            printTree(root->left);
            cout << root->data << endl;
            printTree(root->right);
        }
        // Time Complexity: Worst case O(N) where N is the height of the tree if you are dealing with an unbalanced one
        bool contains(int val) {
            Node* curr = root;
            while (curr != nullptr) {
                if (val < curr->data) {
                    curr = curr->left;
                } else if (val > curr->data) {
                    curr = curr->right;
                } else {
                    return true;
                }
            }
            return false;
        }
        // Time Complexity: Worst case O(N) where N is the height of the tree
        void insertBSTNode(int val) {
            root = insertRecursive(root, val);
        }
        // trying again
        /*
            - if you delete a leaf node, no problem just delete it because will not affect the rest of the tree
            - if you delete a node with 2 children, choose the inorder successor or the inorder predecessor
            - if you delete a node with one child (left or right), you can delete the node after replacing it with its left or right child
        */
        // Time Complexity: Worst case O(N) where N is the height of the tree
        int removeBSTNode(int val) {
            root = deleteRecursive(root, val);
            return val;
        }
    private: //make private helper functions so the caller cannot abuse access
        Node* root;
        Node* insertRecursive(Node* curr, int val) {
            if (curr == nullptr) {
                Node* new_node = new Node; //allocate memory for the new node 
                new_node->data = val;
                new_node->left = nullptr;
                new_node->right = nullptr;
                return new_node;
            } else if (val < curr->data) {
                curr->left = insertRecursive(curr->left, val);
            } else if (val > curr->data) {
                curr->right = insertRecursive(curr->right, val);
            }
            return curr;
        }
        Node* deleteRecursive(Node* curr, int val) {
            if (curr == nullptr) {
                return nullptr;
            } else if (val < curr->data) {
                curr->left = deleteRecursive(curr->left, val);
            } else if (val > curr->data) {
                curr->right = deleteRecursive(curr->right, val);
            } else {
                if (curr->left == nullptr && curr->right == nullptr) { //no children, just delete 
                    delete curr;
                    curr = nullptr; 
                    return nullptr;
                } else if (curr->left == nullptr) { //one child chase 
                    Node* temp = curr->right;
                    delete curr;
                    curr = nullptr; 
                    return temp;
                } else if (curr->right == nullptr) { //one child case 
                    Node* temp = curr->left;
                    delete curr;
                    curr = nullptr; 
                    return temp;
                } else {
                    Node* minimum = findMin(curr->right);
                    curr->data = minimum->data;
                    curr->right = deleteRecursive(curr->right, minimum->data);
                }
            }
            return curr;
        }
        Node* findMin(Node* curr) {
            while (curr->left != nullptr) {
                curr = curr->left;
            }
            return curr;
        }
};



int main() {
    BST tree;
    tree.insertBSTNode(6);
    tree.insertBSTNode(19);
    tree.insertBSTNode(1);
    tree.insertBSTNode(3);
    tree.insertBSTNode(12);
    tree.insertBSTNode(2);
    tree.insertBSTNode(8);
    cout << tree.contains(14) << endl;
    cout << tree.contains(19) << endl;
    cout << tree.contains(6) << endl;
    cout << tree.contains(1) << endl;
    cout << tree.min() << endl;
    cout << tree.max() << endl;
    tree.removeBSTNode(12);
    cout << tree.contains(12) << endl;
    return 0;
}
