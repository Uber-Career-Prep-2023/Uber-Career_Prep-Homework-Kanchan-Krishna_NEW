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

//Time Complexity: O(1) & Space Complexity: O(1)
Node* insertAtFront(Node* head, int d) {
    /*in the best possible situation, assume the head is not null and exists
    although, this function would work if the head is null because the next of insert_this would 
    just be null meaning there is one node in the SLL*/
    //allocate memory for the new node 
    Node* insert_this = new Node;
    insert_this->next = head; 
    insert_this->data = d;
    return insert_this;
}

//Time Complexity: O(N) where N is the # of nodes in the SLL & Space Complexity: O(1)
void insertAtBack(Node* head, int d) {   
    if (head == nullptr) {
    	return;
    }
    Node* insert_this = new Node;	
    Node* curr = head;
    //1 -> 2 -> 3 -> 4
    while (curr->next != nullptr) { //traverse list to get to the end 
	curr = curr->next; 
    }
    curr->next = insert_this; //new "tail"
    insert_this->next = nullptr;
    insert_this->data = d;
    return;
}

//Time Complexity: O(1) because we have access to loc (if not null) & Space Complexity: O(1)
//Assume loc is not nullptr 
void insertAfter(Node* head, Node* loc, int d) {
    if (head == nullptr) {
	return;
    }
    //1 -> 2 -> 3 -> 4 and 3 is loc and insert 5 after loc 
    Node* insert_this = new Node;
    insert_this->data = d; 
    insert_this->next = loc->next;
    loc->next = insert_this; 
    return;
}

//Time Complexity: O(1) & Space Complexity: O(1)
Node* deleteFront(Node* head) {
    if (head == nullptr) { //nothing to delete; don't want to delete memory that does not exist 
	return head;
    }
    Node* curr_head = head; //save a reference to the current head here
    if (curr_head->next == nullptr) { //only 1 node in the SLL
        delete head; 
	head = nullptr;
    } else { //at least 2 nodes in the SLL 1 -> 2 -> 3 then delete memory allocated to 1 and move head
        delete head; 
	head = curr_head->next; //why we saved a copy of it above 
    }
    return head;
} 

//Time Complexity: O(N) where N is the # of nodes in the SLL & Space Complexity: O(1)
void deleteBack(Node* head) {
    if (head == nullptr) { //nothing to delete 
	return;
    } else if (head->next == nullptr) { //only 1 node exists 
	delete head;
        head = nullptr; 
	return;
    }
    Node* curr = head;
    //1 -> 2 -> 3
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
    return;
}

//Time Complexity: O(N) where N is the # of nodes in the list & Space Complexity: O(1)
Node* deleteNode(Node* head, Node* loc) {
    if (head == nullptr) {
	return head;
    } else if (loc == head) {
	head = head->next;
	delete loc;
        loc = nullptr; 
        return head; //new head
    } else {
	Node* prev = head;
        //1 -> 2 -> 3 -> 4 and 3 is loc 
	while (prev->next != loc) {
		prev = prev->next;
	}
	prev->next = loc->next;
	delete loc;
        loc = nullptr;
    }
    return head;
}

//Time Complexity: O(N) where N is the # of nodes in the SLL & Space Complexity: O(1)
int length(Node* head) {
    if (head == nullptr) {
        return 0; 
    }
    int length = 1; //should be at least 1 if head != nullptr 
    Node* curr = head; //1 -> 2 -> 3
    while (curr->next != nullptr) {
        length++;
        curr = curr->next;
    }
    return length;
}

//Time Complexity: O(N) where N is the # of nodes in the SLL & Space Complexity: O(1)
void printList(Node* head) {
    cout << "Printing Singly Linked List" << endl; 
    //1 -> 2 -> 3
    Node* curr = head; 
    while (curr) {
        cout << "Current node: " << curr->data << endl; 
        curr = curr->next; 
    }
    cout << "Done Printing Singly Linked List" << endl;
}

//Time complexity: O(N) where N is the # of nodes in the SLL & Space Complexity: O(1)
Node* reverseIterative(Node* head) {
    if (!head|| !head->next) {
        return head;
    }
    // 1 -> 2 -> 3
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* saved_next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = saved_next;
    }
    return prev;
}

//Time complexity: O(N) where N is the # of nodes in the SLL & Space Complexity: O(1)
Node* reverseRecursiveHelper(Node* prev, Node* curr) {
    if (curr->next == nullptr) {
	curr->next = prev;
	return curr;
    }
    Node* next_head = reverseRecursiveHelper(curr, curr->next);
    curr->next = prev;
    return next_head;
}

//Time complexity: O(N) where N is the # of nodes in the SLL & Space Complexity: O(1) 
Node* reverseRecursive(Node* head) {
    if (head == nullptr) {
	return head;
    }
    return reverseRecursiveHelper(nullptr, head);
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
