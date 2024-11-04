#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

void InsertAtTail(Node *&node, int data, Node *&start)
{
    Node *newNode = new Node(data);
    if (node == nullptr)
    {
        node = newNode;
        start = node;
        node->next = start;
        return;
    }

    Node *temp = node;
    while (temp->next != start)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = start;
}

void Display(Node *head, Node *start)
{
    Node *tmp = head;
    if (tmp == nullptr)
        return;
    do
    {
        cout << tmp->data << "->";
        tmp = tmp->next;
    } while (tmp != start);
    cout << "(back to start)" << endl;
}

int main()
{
    Node *node = nullptr;
    Node *start = node;
    int num;
    cin >> num;
    while (num--)
    {
        int x;
        cin >> x;
        InsertAtTail(node, x, start);
    }

    Display(node, start);
    return 0;
}
