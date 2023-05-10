#include <bits/stdc++.h> 
using namespace std;

/*
Time Taken: 25 min
Space Complexity: O(1)
Technique Used: Linked List One Pointer
*/

class Node {
    public:
        int data;
        Node *next;
};

//Time Complexity: O(N) where N is the # of nodes in the linked list 
void removeDuplicates(Node* head) {
    Node* curr = head;
    Node* n = nullptr;
    if (curr == nullptr) {
        return;
    }
    while (curr->next != nullptr) {
        if (curr->data == curr->next->data) {
            n = curr->next->next;
            delete curr->next;
            curr->next = n;
        }
        else {
            curr = curr->next;
        }
    }
}

void pushNode(Node* head, int d) {
    Node* new_node = new Node();
    new_node->data = d;
    new_node->next = head; 
    head = new_node;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << " " << head->data << endl;
        head = head->next;
    }
}

int main() {
    Node* head = new Node();
    head->data = 6; 
    head->next = nullptr;
    pushNode(head, 5);
    pushNode(head, 4);
    pushNode(head, 3);
    pushNode(head, 3);
    pushNode(head, 1);
    pushNode(head, 0);
    printList(head);
    removeDuplicates(head)
    printList(head);
}