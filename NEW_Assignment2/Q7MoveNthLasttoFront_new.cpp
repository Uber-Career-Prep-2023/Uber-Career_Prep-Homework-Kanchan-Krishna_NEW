#include <bits/stdc++.h>
using namespace std;

/*
Time Taken: 30 min + 10 min for fixes
Space Complexity: O(1)
Technique Used: Linked List One Pointer
*/

//public by default 
struct Node {
	int data;
	Node* next;
};

Node* moveNthLastToFront(Node* head, int k) {
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
    head = insertAtFront(head, 4);
    head = insertAtFront(head, 3);
    head = insertAtFront(head, 2);
    head = insertAtFront(head, 1);
    cout << "" << endl; 
    printList(head);
    cout << "" << endl; 
    head = moveNthLastToFront(head, 3);
    printList(head);
}