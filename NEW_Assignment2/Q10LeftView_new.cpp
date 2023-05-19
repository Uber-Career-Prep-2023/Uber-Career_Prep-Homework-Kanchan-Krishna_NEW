#include <bits/stdc++.h>
using namespace std;

/*
Time Taken: 30 min + 10 min for extra fixes 
Space Complexity: O(1) if you do not count the output
Technique Used: BFS Traversal  
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

vector<int> generateLeftView(Node* root) {
    vector<int> v;
    queue<Node*> q;
    if (root == nullptr) {
        return v;
    }
    q.push(root);
    while (!q.empty()) {
        int count = q.size();
        for (int i = 1; i <= count; i++) {
            Node* n = q.front();
            q.pop();
            if (i == 1) {
                v.push_back(n->data);
            }
            if (n->left) {
                q.push(n->left);
            }
            if (n->right) {
                q.push(n->right);
            }
        }
    }
    return v;
}

void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    cout << root->data << endl;
    printTree(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(6);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(8);
    root->right->left = new Node(19);
    root->right->right = new Node(3);
    cout << "Current Tree: " << endl;
    printTree(root);
    vector<int> v = generateLeftView(root);
    cout << "" << endl;
    cout << "Printing left view now" << endl; 
    for (auto ele : v) {
        cout << ele << endl;
    }
}
