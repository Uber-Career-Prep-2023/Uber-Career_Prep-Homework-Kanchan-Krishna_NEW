#include <bits/stdc++.h>
using namespace std;
// Given a singly linked list, disconnect the cycle, if one exists.

/*
Time Taken: 25 min
Space Complexity: O(1)
Technique Used: Hash linked list nodes or two pointers linked list 
*/

//Time Complexity: O(N) where N is the number of nodes in the linked list 
/*void disconnectCycle(Node* head) {
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

void pushNode(NodeDLL *head, int &d) {
    NodeDLL *new_node = new NodeDLL();
    new_node->data = d;
    new_node->next = head;
    head = new_node;
}*/

/* optimizing space approach using a fast and a slow pointer 
    - the fast pointer will be ahead so if it reaches the end of the linked list, there is no cycle 
    - otherwise you should move slow by 1 node and fast by 2 nodes 
    - to detect the cycle, if fast and slow meet then you have a cycle 
    - to remove the cycle, you would have to set the node's next value to nullptr to break the connection 
*/

struct Node {
    int data;
    Node* next;
};

Node* detectCycle(Node* head) {
    // 1-> 2 -> 3 -> 1 (cycle)
    Node* slow = head; 
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) { //if fast -> next is nullptr that means there is no cycle (reached end)
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return slow; //you can return either one right?
        }
    }
    return nullptr;
}

void disconnectCycle(Node* head) {
    Node* slow = detectCycle(head);
    if (slow == nullptr) {
        return; 
    }
    Node* curr = head; 
    while (curr != nullptr) {
        Node* start = slow;
        while (start->next != slow && start->next != curr) {
            start = start->next;
        }
        if (start->next == curr) {
            start->next = nullptr;
            break;
        }
        curr = curr->next; 
    }
}

//Time Complexity: O(1) & Space Complexity: O(1)
Node* insertAtFront(Node* head, int d) {
    /*in the best possible situation, assume the head is not null and exists
    although, this function would work if the head is null because the next of insert_this would 
    just be null meaning there is one node in the SLL*/
    //allocate memory for the new node 
	Node* insert_this = new Node;
	insert_this->next = head;
	insert_this->data = d;
	return insert_this;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << " " << head->data << endl;
        head = head->next;
    }
}

int main() {
    Node* head = nullptr; 	
	cout << "Creating linked list" << endl; 
 	head = insertAtFront(head, 5);
    Node* cycle_start = head; 
    head = insertAtFront(head, 4);
    head = insertAtFront(head, 3);
    head = insertAtFront(head, 2);
    head = insertAtFront(head, 1);
    cycle_start->next = head; 
    cout << "" << endl; 
    //printList(head); not going to print otherwise will exceed runtime
    disconnectCycle(head);
    cout << "" << endl; 
    printList(head);
}
