#include <bits/stdc++.h>
using namespace std;

/*
Time Taken: 10 min
Space Complexity: O(1)
Technique Used: DLL Two Pointers 
*/

// Given a doubly linked list, determine if it is a palindrome.
class NodeDLL {
    public:
        int data;
        NodeDLL* next;
        NodeDLL* prev;
};

//Time Complexity: log(n) since we are using two pointers (left and right)
bool isPalindrome(NodeDLL* l) {
    if (!l) {
        return true;
    }
    NodeDLL* r = l;
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

void pushNode(NodeDLL* head, int &d) {
    NodeDLL* new_node = new NodeDLL();
    new_node->data = d;
    new_node->next = head;
    head = new_node;
}

int main() {
    NodeDLL* head = new NodeDLL();
    head->data = 6;
    head->next = nullptr;
    pushNode(head, 5);
    pushNode(head, 4);
    pushNode(head, 3);
    pushNode(head, 3);
    pushNode(head, 1);
    pushNode(head, 0);
    cout << "Is this DLL a palindrome?" << isPalindrome(head) << endl;
}