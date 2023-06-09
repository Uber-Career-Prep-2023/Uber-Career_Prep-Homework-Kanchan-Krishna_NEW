#ifndef Q1SINGLYLINKEDLIST_HPP
#define Q1SINGLYLINKEDLIST_HPP

#include <bits/stdc++.h>
using namespace std;
class SinglyLinkedList {
    public:
        struct Node {
            //used Base Member Initialization List 
            Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
            int data;
            Node* next;
        };
        //constructor 
        SinglyLinkedList();
        //destructor 
        ~SinglyLinkedList();
        //prints the entire list (used for test cases)
        void printList(Node* head);
        Node* insertAtFront(int val);
        void insertAtBack(int val);
        void insertAfter(int val, Node*& loc);
        Node* deleteFront();
        void deleteBack();
        Node* deleteNode(Node* loc);
        int length();
        Node* reverseIterative();
        Node* reverseRecursive(Node* head);
    private:
        Node* head;
};

#endif