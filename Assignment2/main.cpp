#include <iostream>
#include <bits/stdc++.h>
#include "Q1SinglyLinkedList.hpp"

//3, 5, 6, 7, 8, 9, 10, 11

int main() {
    //Test for Q1
    SinglyLinkedList ll; 
    ll.insertAtFront(3);
    ll.insertAtFront(2);
    ll.insertBack(1);
    ll.printList(); 
    ll.reverseIterative(); 
    ll.printList(); 
    ll.deleteNode(nullptr); 
    ll.printList(); 
    //Test for Q2
    DoublyLinkedList dll; 
    dll.insertAtFront(3);
    dll.insertAtFront(2);
    dll.insertAtFront(1);
    dll.printList(); 
    dll.reverseIterative(); 
    dll.printList();
    // Test for Q3
    // Test for Q4
    // Test for Q5
    // Test for Q6
    // Test for Q7
    // Test for Q8
    // Test for Q9
    // Test for Q10
    // Test for Q11
}