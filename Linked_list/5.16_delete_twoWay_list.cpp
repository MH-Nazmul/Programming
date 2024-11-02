#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int n)
    {
        data = n;
        next = nullptr;
        prev = nullptr;
    }
};
void InsertAtTail(Node *&node, int n)
{
    Node *add = new Node(n);
    if (node == nullptr)
    {
        node = add;
        return;
    }
    Node *tmp = node;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = add;
    add->prev = tmp;
}
void _delete(Node *&node, int item)
{
    Node *tmp = node;
    if (tmp == nullptr)
    {
        cout << "underfolw";
        return;
    }
    while (tmp->data != item)
    {
        if (tmp->next == nullptr)
        {
            cout << "item doesn't exist";
            return;
        }
        tmp = tmp->next;
    }
    if (tmp->next == nullptr)
    {
        tmp->prev->next = nullptr;
    }
    else if (tmp->prev == nullptr)
    {
        tmp = tmp->next;
        tmp->prev = nullptr;
        node = tmp;
    }
    else
    {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }
}
void Display(Node *node)
{
    Node *tmp = node;

    while (tmp != nullptr)
    {
        cout << tmp->data << "->";
        tmp = tmp->next;
    }
}

int main()
{
    Node *node = nullptr;
    InsertAtTail(node, 1);
    InsertAtTail(node, 2);
    InsertAtTail(node, 3);
    InsertAtTail(node, 4);
    InsertAtTail(node, 5);
    cout << "before deletion:";
    Display(node);
    cout << "\n";
    int item;
    cout << "Enter item for deletion:";
    cin >> item;
    _delete(node, item);
    cout << "\n";
    cout << "after deletion:";
    Display(node);
    return 0;
}