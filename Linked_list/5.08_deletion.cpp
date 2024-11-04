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
void _delete(Node *&node, int n)
{
    Node *tmp = node;
    if (node == nullptr)
        {cout<<"underflow";return;}
    while (tmp->next->data != n)
    {
        tmp = tmp->next;
        if(tmp->next==nullptr){
            cout<<"item doesn't exist;";return;
        }
        
    }
    tmp->next = tmp->next->next;
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
    cout << "before deleting: ";
    Display(node);
    cout << "insert the node which to delete:\n";
    int n;
    cin >> n;
    _delete(node, n);
    cout << "\n";
    cout << "after deleting: ";
    Display(node);
    return 0;
}