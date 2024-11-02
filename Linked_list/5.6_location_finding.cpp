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
Node* location_find(Node *&node, int n)
{
    Node *tmp = node;
    if (node == nullptr)
        return nullptr;
    while (tmp->data != n)
    {
        tmp = tmp->next;
    }
    return tmp->next;
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
    Display(node);
    cout << "insert the node which loc is to be found:\n";
    int n;
    cin >> n;
    cout<<location_find(node,n);
    return 0;
}