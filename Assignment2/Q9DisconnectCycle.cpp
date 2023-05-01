#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int removeCycle(Node* head_list) {
    Node* slow = head_list;
    Node* fast = head_list;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            removeLoop(slow, head_list);
            return 1;
        }
    }
    return 0;
}

void removeLoop(Node* start_loop, Node* head) {
    Node* pointer1 = start_loop;
    Node* pointer2 = start_loop;
    unsigned int k = 1, i;
    while (pointer1->next != pointer2)
    {
        pointer1 = pointer1->next;
        k++;
    }
    pointer1 = head;
    pointer2 = head;
    for (i = 0; i < k; i++) {
        pointer2 = pointer2->next;
    }
    while (pointer2 != pointer1) {
        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
    }

    while (pointer2->next != pointer1) {
        pointer2 = pointer2->next;
    }
    pointer2->next = NULL;
}
