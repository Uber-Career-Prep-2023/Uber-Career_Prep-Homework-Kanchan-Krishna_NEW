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
        SinglyLinkedList() : head(nullptr), tail(nullptr) {}
        //destructor 
        ~SinglyLinkedList();
        //prints the entire list (used for test cases)
        void printList(const Node* head);
        Node* insertAtFront(int val);
        void insertAtBack(int val);
        void insertAfter(int val, Node*& loc);
        Node* deleteFront();
        void deleteBack();
        Node* deleteNode(Node* loc);
        int length();
        Node* reverseIterative();
        Node* reverseRecursive();
    private:
        Node* head;
};

#endif