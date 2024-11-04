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
    n--;
    Node *itm = new Node(item);
    Node *tmp = node;
    if (node == nullptr)
        node = itm;
    for(int i=0;i<n-1;i++)
    {
        tmp = tmp->next;
    }
    if(n==0){
        itm->next=tmp;
        node=itm;
        return;
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
    cout << "insert the index where to add new node :\n";
    int n, item;
    cin >> n ;
    cout << "insert the item :\n";
    cin>>item;
    cout << "before adding node: ";
    Display(node);
    add_after(node, n, item);
    cout << "\n";
    cout << "after adding node "<<item<<" at "<<n<<"th index : ";
    Display(node);
    return 0;
}