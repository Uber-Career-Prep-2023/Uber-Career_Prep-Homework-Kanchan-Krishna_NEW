#include <iostream>
#include <bits/stdc++.h>
#include "Q1SinglyLinkedList.hpp"
#include "Q2DoublyLinkedList.hpp"

int main()
{
    // Test for Q1
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
    DoublyLinkedList dll;
    dll.insertAtFront(3);
    dll.insertAtFront(2);
    dll.insertAtFront(1);
    dll.printList();
    dll.reverseIterative();
    dll.printList();
    // Test for Q3
    BST b; 
    b.insert(4);
    b.insert(4); 
    b.insert(10);
    b.insert(5);
    b.insert(9);
    b.insert(2);
    b.insert(18);
    b.printTree(); 
    b.deleteVal(10);
    b.printTree();
}