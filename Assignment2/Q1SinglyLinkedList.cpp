#include "Q1SinglyLinkedList.hpp"
#include <bits/stdc++.h>
using namespace std;

/*
Time Taken: 30 min
Space Complexity: O(n) where N is the # of nodes used 
Technique Used: Linked List Creation
*/

//inserts a new node at the back of the singly linked list 
//time complexity: O(N) where N is the # of nodes in the SLL; O(1) if only 1 node in SLL
void SinglyLinkedList::insertAtBack(int val) {
    //create the new node with value val 
    Node* new_node = new Node(val, nullptr);
    if (!head) { //if SLL is empty 
        head = new_node;
    } else {
        Node* curr = head;
        while (curr->next) { //get to the back of the list 
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

// inserts a new node at the front of the singly linked list
// time complexity: O(1)
SinglyLinkedList::Node* SinglyLinkedList::insertAtFront(int val) {
    //create the new node whose next is the current head 
    Node* new_node = new Node(val, head);
    head = new_node;
    return head;
}

// inserts a new node after the specified location
// time complexity: O(1)
void SinglyLinkedList::insertAfter(int val, Node*& loc) {
    //if the node loc does not exist, don't do anything 
    if (!loc) {
        return;
    }
    //no need to iterate through the entire SLL
    Node* new_node = new Node{val, loc->next};
    loc->next = new_node;
}

// deletes node at the front of the singly linked list
// time complexity: O(1)
SinglyLinkedList::Node* SinglyLinkedList::deleteFront() {
    if (!head) { //nothing to delete 
        return nullptr;
    }
    Node* curr = head;
    head = head->next; //change the new head to be the next of the current head 
    curr->next = nullptr; //dissolve the connection
    delete curr;
    curr = nullptr; // so no dangling pointer
    return head; //(new head)
}

// deletes node at the back of the singly linked list
// time complexity: O(N) where N is the # of nodes in the SLL; O(1) if only 1 node in SLL
void SinglyLinkedList::deleteBack()
{
    if (!head) {
        return;
    }
    if (!head->next) { //just one node in the singly linked list 
        delete head;
        head = nullptr;
    }
    Node* curr = head;
    //1 -> 2 -> 3
    while (curr->next->next != nullptr)
    {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
}

//deletes node at the specified location 
//time complexity: O(N) where N is the number of nodes before loc; O(1) if loc is at the front of the list 
SinglyLinkedList::Node* SinglyLinkedList::deleteNode(Node* loc) {
    if (!head || !loc) {
        return nullptr;
    } else if (loc == head) {
        deleteFront();
    }
    //1 -> 2 -> 3 -> 4 and you want to delete 3; 3 = loc 
    Node* curr = head;
    while (curr->next != loc && curr != nullptr) {
        curr = curr->next;
    }
    curr->next = loc->next; //skip over the node you want to delete 
    delete loc;
    loc = nullptr; 
    return head;
}

//deletes all the nodes in a singly linked list 
//time complexity: O(N) where N is the # of nodes in the SLL
SinglyLinkedList::~SinglyLinkedList() {
    //1 -> 2 -> 3 
    Node* curr = head;
    while (curr != nullptr) {
        Node* saved_next = curr->next;
        delete curr;
        curr = nullptr;
        curr = saved_next;
    }
}

// returns the length of the singly linked list
// time complexity: O(N) where N is the # of nodes in the SLL
int SinglyLinkedList::length() {
    //1 -> 2 -> 3
    int length = 0;
    Node* curr = head;
    while (curr != nullptr) {
        length++;
        curr = curr->next;
    }
    return length;
}

//time complexity: O(N) where N is the # of nodes in the SLL
void SinglyLinkedList::printList(Node* head) {
    cout << "Printing Singly Linked List" << endl; 
    //1 -> 2 -> 3
    Node* curr = head; 
    while (curr) {
        cout << "Current node: " << curr->val << endl; 
        curr = curr->next; 
    }
    cout << "Done Printing Singly Linked List" << endl;
}

// reverses the singly linked list iteratively
// time complexity: O(N) where N is the # of nodes in the SLL
SinglyLinkedList::Node* SinglyLinkedList::reverseIterative() {
    if (!head|| !head->next) {
        return head;
    }
    // 1 -> 2 -> 3
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* saved_next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = saved_next;
    }
    return prev;
}

// time complexity: O(N) where N is the # of nodes in the SLL
SinglyLinkedList::Node* SinglyLinkedList::reverseRecursive(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* next_head = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return next_head;
}