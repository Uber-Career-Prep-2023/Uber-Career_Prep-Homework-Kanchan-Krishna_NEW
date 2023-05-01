#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

bool isPalindrome(Node *left)
{
    if (!left)
    {
        return true;
    }
    Node* right = left;
    while (right->next != nullptr) {
        right = right->next;
    }
    while (left != right) {
        if (left->data != right->data) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    return true;
}