#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int n){
        data=n;
        next=nullptr;
        prev=nullptr;
    }
};
    void InsertAtTail(Node *&node,int n){
        Node *add=new Node(n);
        if(node==nullptr){
            node=add;
            return;
        }
        Node *tmp = node;
        while(tmp->next!=nullptr){
            tmp=tmp->next;
        }
        tmp->next=add;
        add->prev=tmp;
    }
    void Display(Node *node){
        Node *tmp=node;
        cout<<"forward travarsing by node->next:";
        while(tmp!=nullptr){
            cout<<tmp->data<<"->";
            tmp=tmp->next;
        }
    }

int  main(){
    Node *node=nullptr;
    InsertAtTail(node, 1);
    InsertAtTail(node, 2);
    InsertAtTail(node, 3);
    InsertAtTail(node, 4);
    InsertAtTail(node, 5);
    Display(node);
    return 0;
}