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

void InsertAtTail(Node *&node, int data, Node *start)
{
    Node *head = new Node(data);
    Node *temp = node;
    if (node == nullptr)
    {
        node = head;
        node->next = start;
        return;
    }
    while (temp->next != start)
        temp = temp->next;
    temp->next = head;
}
void Display(Node *head, Node *start)
{
    while (head != start)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}
void search(Node *node, int key, Node *start)
{
    while (node->next != start)
    {
        if (node->next->data == key)
        {
            cout << "founded \n location is" << node->next<<"\n preceding Node is:  "<<node->data;
            return;
        }
        else if (node->data == key)
        {
            cout << "this is the first element of this list;";
            return;
        }
        node = node->next;
    }
    {
        cout << "Not founded";
        return;
    }
}

int main()
{
    Node *node = nullptr;
    Node *start = node;
    InsertAtTail(node, 1, start);
    InsertAtTail(node, 4, start);
    InsertAtTail(node, 5, start);
    InsertAtTail(node, 8, start);
    Display(node, start);
    cout << "enter the nod to be found: ";
    int n;
    cin >> n;
    search(node, n, start);
    return 0;
}