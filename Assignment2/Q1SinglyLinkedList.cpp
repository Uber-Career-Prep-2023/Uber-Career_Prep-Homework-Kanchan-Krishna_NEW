#include "Q1SinglyLinkedList.h"
#include <bits/stdc++.hpp>

//inserts a new node at the back of the singly linked list 
void SinglyLinkedList::insertAtBack(int val) {
    Node* new_node = new Node(val, nullptr);
    if (!head) {
        head = new_node;
    } else {
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

//inserts a new node at the front of the singly linked list 
SinglyLinkedList::Node* SinglyLinkedList::insertAtFront(int val) {
    Node* new_node = new Node(val, head);
    head = newNode;
    return head;
}

//inserts a new node after the specified location
void SinglyLinkedList::insertAfter(int val, Node*& loc) {
    if (!loc) {
        return;
    }
    //no need to iterate through the entire SLL
    Node* new_node = new Node{val, loc->next};
    loc->next = new_node;
}

//deletes node at the front of the singly linked list 
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

//deletes node at the back of the singly linked list 
void SinglyLinkedList::deleteBack() {
    if (!head) {
        return;
    }
    if (!head->next) { //just one node in the singly linked list 
        delete head;
        head = nullptr;
    }
    Node* curr = head;
    while (curr->next->next != nullptr)
    {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
}

//deletes node at the specified location 
SinglyLinkedList::Node* SinglyLinkedList::deleteNode(Node* loc) {
    if (!head || !loc) {
        return nullptr;
    } else if (loc == head) {
        deleteFront();
    }
    Node* curr = head;
    while (curr->next != loc && curr != nullptr) {
        curr = curr->next;
    }
    curr->next = loc->next;
    delete loc;
    return head;
}

//deletes all the nodes in a singly linked list 
SinglyLinkedList::~SinglyLinkedList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* saved_next = curr->next;
        delete curr;
        curr = nullptr;
        curr = saved_next;
    }
}

//returns the length of the singly linked list
int SinglyLinkedList::length() {
    int length = 0;
    Node* curr = head;
    while (curr != nullptr) {
        length++;
        curr = curr->next;
    }
    return length;
}

//reverses the singly linked list iteratively 
SinglyLinkedList::Node* SinglyLinkedList::reverseIterative() {
    if (!head|| !head->next) {
        return head;
    }
    Node* prev = nullptr;
    Node* curr = head;
    Node* saved_next = nullptr;
    while (curr != nullptr) {
        saved_next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = saved_next;
    }
    return prev;
}