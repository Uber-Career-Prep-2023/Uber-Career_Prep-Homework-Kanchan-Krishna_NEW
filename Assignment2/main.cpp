#include <iostream>
#include <bits/stdc++.h>
#include "Q1SinglyLinkedList.hpp"

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
    // Test for Q2
}