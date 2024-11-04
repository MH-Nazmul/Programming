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
void find_node(Node *&node, int n)
{
    Node *tmp = node;
    if (node ->data==n)
    {
        cout << "loc=NULL;";
        return;
    }
    while (tmp->next->data != n)
    {
        tmp = tmp->next;
        if (tmp->next == nullptr)
        {
            cout << "item doesn't exist;";
            return;
        }
    }
    cout<<"preceding node: "<<tmp->data<<"\n";
    cout<<"location : "<<tmp->next;
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
    cout << "insert the node which loc to be found:\n";
    int n;
    cin >> n;
    find_node(node, n);
    return 0;
}