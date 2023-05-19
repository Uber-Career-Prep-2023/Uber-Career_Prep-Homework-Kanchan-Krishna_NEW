#include <bits/stdc++.h> 
using namespace std;

/*
Time Taken: 25 min + 15 for corrections 
Space Complexity: O(1)
Technique Used: Linked List One Pointer
*/

//public by default 
struct Node {
	int data;
	Node* next;
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
    head = insertAtFront(head, 2);
    cout << "" << endl; 
    printList(head);
    cout << "" << endl; 
    removeDuplicates(head);
    printList(head);
}