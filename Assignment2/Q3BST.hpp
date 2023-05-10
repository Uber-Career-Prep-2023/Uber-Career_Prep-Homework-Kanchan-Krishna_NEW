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
        void insert(int val);
        int deleteVal(int val);
        void printTree(Node *root); 
    private:
        Node* root;
        Node* findMin(Node *node);
        Node* insert(Node *node, int val);
        Node* deleteVal(Node *node, int val);
};
#endif