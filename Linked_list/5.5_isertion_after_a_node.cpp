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
void add_after(Node *&node, int n, int item)
{
    Node *itm = new Node(item);
    Node *tmp = node;
    if (node == nullptr)
        node = itm;
    while (tmp->data != n)
    {
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
    cout << "insert the node where to find its loc and item:\n";
    int n, item;
    cin >> n >> item;
    cout << "before adding: ";
    Display(node);
    add_after(node, n, item);
    cout << "\n";
    cout << "after adding: ";
    Display(node);
    return 0;
}