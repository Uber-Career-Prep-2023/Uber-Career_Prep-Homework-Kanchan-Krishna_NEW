/*Implement the following methods.Rather than having a separate linked list class, we will pass a Node struct that represents the head of the list(this is common practice in interview questions).The linked list article includes a Node struct definition in a number of common languages(C++, Python, Java, JavaScript);
feel free to use it in your implementation.For simplicity, you can make your nodes store integers rather than generic data types.In each of the methods, you should use pointers in languages that support pointers(e.g., Node *in C++) or a reference in languages that support references(e.g., Python).*/

#include <bits/stdc++.h>
using namespace std;
class SinglyLinkedList {
    public:
        struct Node {
            //used BMI 
            Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
            int data;
            Node* next;
        };
        SinglyLinkedList() : head(nullptr), tail(nullptr) {}
        ~SinglyLinkedList();
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