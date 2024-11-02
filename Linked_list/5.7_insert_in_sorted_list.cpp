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
void add(Node *&node, int n)
{
    Node *itm = new Node(n);
    Node *tmp = node;
    if (node == nullptr)
        node = itm;
    while (tmp->next->data < n)
    {
        if(tmp->next->next==nullptr){tmp=tmp->next;break;};
        tmp = tmp->next;
    }
    itm->next = tmp->next;
    tmp->next = itm;
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
    InsertAtHead(node, 8);
    InsertAtHead(node, 5);
    InsertAtHead(node, 4);
    InsertAtHead(node, 1);
    InsertAtHead(node, 0);
    cout << "before add: ";
    Display(node);
    cout << "insert the node to be added:\n";
    int n;
    cin >> n;
    add(node, n);
    cout << "after add: ";
    Display(node);
    return 0;
}