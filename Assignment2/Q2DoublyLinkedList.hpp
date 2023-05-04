#ifndef Q2DOUBLYLINKEDLIST_HPP
#define Q2DOUBLYLINKEDLIST_HPP
#include <bits/stdc++.h>
using namespace std;
class DoublyLinkedList {
public:
    struct Node {
        // used Base Member Initialization List
        Node(int data = 0, Node *next = nullptr) : data(data), next(next) {}
        int data;
        Node* next;
        Node* prev; 
    };
    // constructor
    DoublyLinkedList() : head(nullptr) {}
    // destructor
    ~DoublyLinkedList();
    // prints the entire list (used for test cases)
    void printList(const Node *head);
    Node *insertAtFront(int val);
    void insertAtBack(int val);
    void insertAfter(int val, Node *&loc);
    Node *deleteFront();
    void deleteBack();
    Node *deleteNode(Node *loc);
    int length();
    Node *reverseIterative();
    Node *reverseRecursive();
private:
    Node *head;
};

#endif