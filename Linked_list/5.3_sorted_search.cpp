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
void search(Node *node, int key)
{
    while (node->next != nullptr)
    {
        if (node->data == key)
        {
            cout << "Founded at: " << node << " ";
            return;
        }
        if (node->data > key)
        {
            cout << "Not exist";
            return;
        }
        node = node->next;
    }
    cout << "Not exist";
    return;
}
int main()
{
    Node *node = nullptr;
    cout << "enter the numbers of nodes you want to add:\n";
    int num;
    cin >> num;
    cout << "enter the nodes:\n";
    vector<int> v(num);
    for (int i = 0; i < num; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < num; i++)
    {
        InsertAtTail(node, v[i]);
    }

    Display(node);
    cout << "enter the node to search:";
    int nd;
    cin >> nd;
    search(node, nd);
    return 0;
}