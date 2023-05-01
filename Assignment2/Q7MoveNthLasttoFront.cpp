#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void moveToFront(Node *head_h)
{
    if (head_h == nullptr || head_h->next == nullptr)
    {
        return;
    }
    Node *penultimate = nullptr;
    Node *last = head_h;
    while (last->next != nullptr)
    {
        penultimate = last;
        last = last->next;
    }
    penultimate->next = nullptr;
    last->next = *head_h;
    head_h = last;
}