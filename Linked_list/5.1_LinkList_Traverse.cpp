#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
void InsertAtHead(Node *&node, int val)
{
    Node *n = new Node(val);
    n->next = node;
    node = n;
}
void InsertAtTail(Node *&node, int data)
{
    Node *head = new Node(data);
    Node *temp = node;
    if (node == nullptr)
    {
        node = head;
        return;
    }
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = head;
}
void Display(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *node = nullptr;
    InsertAtTail(node, 1);
    InsertAtTail(node, 4);
    InsertAtTail(node, 5);
    InsertAtTail(node, 8);
    InsertAtHead(node, 0);
    Display(node);
    return 0;
}