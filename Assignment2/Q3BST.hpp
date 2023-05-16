#ifndef Q3BST_hpp
#define Q3BST_hpp
#include <bits/stdc++.h>

using namespace std;

class BST {
    public:
        class Node {
            int val;
            Node* left;
            Node* right;
            Node(int val) : val(val), left(nullptr), right(nullptr) {}
        };
        int min();
        int max();
        bool contains(int val);
        Node* insertBSTNode(Node* node, int val);
        int findInorderSuccessor(Node* root);
        int findInorderPredecessor(Node* root);
        Node* deleteNode(Node *root, int &delete_this);
        void printTree(Node* root);
        private:
            Node *root;
        };
#endif