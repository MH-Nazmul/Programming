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
    cout << "enter the numbers of nodes you want to add:\n";
    int num;
    cin >> num;
    cout << "enter the nodes:\n";
   
    for (int i = 0; i < num; i++)
    {
        int x;
        cin >> x;
        InsertAtHead(node, x);
    }
    Display(node);
    return 0;
}