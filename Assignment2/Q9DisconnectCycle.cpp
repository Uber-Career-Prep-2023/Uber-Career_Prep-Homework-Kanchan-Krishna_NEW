#include <bits/stdc++.h>
using namespace std;
// Given a singly linked list, disconnect the cycle, if one exists.

/*
Time Taken: 25 min
Space Complexity: O(1)
Technique Used: Hash linked list nodes
*/

class Node {
    public:
        int data;
        Node* next;
};

//Time Complexity: O(N) where N is the number of nodes in the linked list 
void disconnectCycle(Node* head) {
    unordered_map<Node*, int> node_map;
    Node* last = nullptr;
    while (head != nullptr) {
        if (node_map.find(head) == node_map.end()) {
            node_map[head]++; //increase the freq count
            last = head;
            head = head->next;
        } else {
            last->next = nullptr;
            break;
        }
    }
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
    Node* cycle = new Node(); 
    cycle->next = head; 
    cycle->data = 10; 
    printList(head); 
}