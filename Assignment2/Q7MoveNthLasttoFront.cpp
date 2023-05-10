#include <bits/stdc++.h>
using namespace std;

/*
Time Taken: 30 min
Space Complexity: O(1)
Technique Used: Linked List One Pointer
*/

class Node {
    public:
        int data;
        Node* next;
};

Node* moveNthLastToFront(Node* head, int& k) {
    if (head == nullptr) {
        return nullptr; 
    }
    Node* curr = head;
    int length = 0;
    while (curr != nullptr) {
        length++;
        curr = curr->next;
    }
    if (k > length) {
        return head;
    }
    curr = head;
    for (int i = 1; i < length - k; i++) {
        curr = curr->next;
    }
    Node* cur = curr->next;
    curr->next = cur->next;
    cur->next = head;
    return cur;
}

void pushNode(Node* head, int& d) {
    Node *new_node = new Node();
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
    moveNthLastToFront(head, 2)
    printList(head);
}