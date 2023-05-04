#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

//time complexity: O(1) if you have reference to the head 
Node* DoublyLinkedList::insertAtFront(Node* head, int val) {
    Node* curr = new Node;
    curr->data = val;
    curr->prev = nullptr;
    curr->next = head;
    if (head != nullptr) {
        head->prev = curr;
    }
    head = curr; 
    return curr; //or head 
}

//time complexity: O(N) where N is the # of nodes; O(1) if you had a tail 
void DoublyLinkedList::insertAtBack(Node* head, int val) {
    Node* curr = new Node;
    curr->data = val;
    curr->next = nullptr;
    if (!head) { //just one node in the doubly linked list 
        curr->prev = nullptr;
        head = curr;
        return;
    }
    Node* curr2 = head;
    while (curr2->next != nullptr) {
        curr2 = curr2->next;
    }
    curr2->next = curr;
    curr->prev = curr2;
    curr->next = nullptr;
}

// time complexity: O(N) where N is the number of nodes in the DLL 
void DoublyLinkedList::insertAfter(Node* head, int val, Node* loc) {
    Node* curr = new Node;
    curr->data = val;
    Node* prev = nullptr;
    Node* curr2 = head;
    while (curr2 != loc && curr2 != nullptr) {
        prev = curr2;
        curr2 = curr2->next;
    }
    if (curr2 == nullptr) { //loc node does not exist 
        delete curr;
        return;
    } else if (curr2->next != nullptr) { 
        curr2->next->prev = curr;
        curr->next = curr2->next;
    }
    curr->prev = curr2;
    curr2->next = curr;
}

// time complexity: O(1) if you have reference to head 
Node* DoublyLinkedList::deleteFront(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* curr = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete curr;
    curr = nullptr; 
    return head;
}

// time complexity: O(N) where N is the # of nodes in the DLL; O(1) if you had a tail
void DoublyLinkedList::deleteBack(Node* head) {
    if (head == nullptr) {
        return;
    } else if (head->next == nullptr) { 
        delete head;
        head = nullptr;
    } else {
        Node* curr = head;
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
    }
}

// time complexity: O(N) where N is the # nodes in the DLL 
Node* DoublyLinkedList::deleteNode(Node* head, Node* loc) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr && curr != loc) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr) {
        return head; //nothing to delete 
    }
    if (prev == nullptr) { 
        head = curr->next;
    } else {
        prev->next = curr->next;
    } if (curr->next != nullptr) { 
        curr->next->prev = prev;
    }
    delete curr;
    return head;
}

// time complexity: O(N) where N is the # of nodes in the DLL 
int DoublyLinkedList::length(Node* head) {
    //same as SLL implementation
    if (head == nullptr) {
        return 0;
    }
    Node* curr = head;
    int length = 0;
    while (curr != nullptr) {
        curr = curr->next;
        length++;
    }
    return length;
}

// time complexity: O(N) where N is the # of nodes in the DLL
Node* DoublyLinkedList::reverseIterative(Node* head) {
    Node* temp = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != nullptr) {
        head_ref = temp->prev;
    }
}

// time complexity: O(N) where N is the # of nodes in the DLL
Node* DoublyLinkedList::reverseRecursive(Node* head) {
    if (!head) {
        return nullptr;
    }
    //swap the prev and next pointers 
    Node* temp = head->next;
    head->next = head->prev;
    head->prev = temp;
    if (!head->prev) {
        return head;
    }
    return reverseRecursive(head->prev);
}

//time complexity: O(N) where N is the # of nodes in the DLL 
void DoublyLinkedList::printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}