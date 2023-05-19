#include <bits/stdc++.h>
using namespace std;

/*
Time Taken: 30 min + 15 min extra for corrections 
Technique Used: Linked List Creation
Time Complexity and Space Complexity are listed for each individual method
*/

//public by default 
struct Node {
	int data;
	Node* next;
};

//Time Complexity: O(1) if you have reference to the head; Space Complexity: O(1)
Node* insertAtFront(Node* head, int val) {
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

//Time complexity: O(N) where N is the # of nodes; O(1) if you had a tail; Space Complexity: O(1)
void insertAtBack(Node* head, int val) {
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

// Time Complexity: O(N) where N is the number of nodes in the DLL; Space Complexity: O(1) 
void insertAfter(Node* head, int val, Node* loc) {
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

//Time Complexity: O(1) if you have reference to head; Space Complexity: O(1)
Node* deleteFront(Node* head) {
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

//Time Complexity: O(N) where N is the # of nodes in the DLL; O(1) if you had a tail; Space Complexity: O(1)
void deleteBack(Node* head) {
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

//Time complexity: O(N) where N is the # nodes in the DLL; Space Complexity: O(1)
Node* deleteNode(Node* head, Node* loc) {
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

//Time Complexity: O(N) where N is the # of nodes in the DLL; Space Complexity: O(1)
int length(Node* head) {
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

//Time Complexity: O(N) where N is the # of nodes in the DLL; Space Complexity: O(1)
Node* reverseIterative(Node* head) {
    Node* temp = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != nullptr) {
        head = temp->prev;
    }
}

//Time complexity: O(N) where N is the # of nodes in the DLL; Space Complexity: O(N)
Node* reverseRecursiveHelper(Node* head) {
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
    return reverseRecursiveHelper(head->prev);
}

//Time complexity: O(N) where N is the # of nodes in the DLL; Space Complexity: O(N) 
Node* reverseRecursive(Node* head){
	if (head == nullptr) {
		return head;
    }
	return reverseRecursiveHelper(head);
}

//time complexity: O(N) where N is the # of nodes in the DLL 
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
    Node* head = nullptr; 	
	cout << "Creating linked list" << endl; 
	head = insertAtFront(head, 6);
	insertAfter(head, head, 87);	
	insertAfter(head, head, 12);	
	head = insertAtFront(head, 10);
	printList(head);
	cout << "" << endl;
	head = reverseIterative(head);
	printList(head);
	cout << "" << endl;
    deleteBack(head);
    printList(head);
	cout << "" << endl;
	cout << "Length: " << length(head) << endl; 
	head = reverseRecursive(head);
	printList(head);
}