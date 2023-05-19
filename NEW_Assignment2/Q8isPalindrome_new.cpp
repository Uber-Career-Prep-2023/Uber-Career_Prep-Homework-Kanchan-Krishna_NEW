#include <bits/stdc++.h>
using namespace std;

/*
Time Taken: 10 min + 15 min for fixes 
Space Complexity: O(1)
Technique Used: DLL Two Pointers 
*/

//public by default 
struct Node {
    int data;
    Node* next;
    Node* prev; 
};

/*Time Complexity: O(N) since N is the # of nodes (even if you are using 2 pointers), the entire 
problem is dependent upon the number of nodes in the linked list*/
bool isPalindrome(Node* l) {
    if (!l) {
        return true;
    }
    Node* r = l;
    //get the right pointer to start at the very end of the list 
    while (r->next != nullptr) {
        r = r->next;
    }
    while (l != r) {
        if (l->data != r->data) {
            return false;
        }
        l = l->next;
        r = r->prev;
    }
    return true;
}

//Time Complexity: O(1) & Space Complexity: O(1)
Node* insertAtFrontofDLL(Node* head, int d) {
    //assume the head exists and is not null
    Node* insert_this = new Node;
    insert_this->next = head;
    insert_this->prev = nullptr; 
    insert_this->data = d;
    return insert_this;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << " " << head->data << endl;
        head = head->next;
    }
}

int main() {
    Node* head = nullptr; 	
    cout << "Creating doubly linked list" << endl; 
    head = insertAtFrontofDLL(head, 5);
    head = insertAtFrontofDLL(head, 4);
    head = insertAtFrontofDLL(head, 3);
    head = insertAtFrontofDLL(head, 4);
    head = insertAtFrontofDLL(head, 5);
    cout << "" << endl; 
    printList(head);
    bool result = isPalindrome(head);
    if (result == 0) {
        cout << "This doubly linked list is not a palindrome";
    } else {
        cout << "This doubly linked list is a palindrome";
    }
}
