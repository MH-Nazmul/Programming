#include<bits/stdc++.h>
using namespace std;
void _insert(int _stack[],int &top,int mx,int item)
{
    if(top==mx-1){cout<<"overflow";return;}
    top++;
    _stack[top]=item;
    return;
}
int main()
{
    int _stack[8]={0,0,0,0,0,0,0,0},top=-1;
    _insert(_stack,top,8,5);
    _insert(_stack,top,8,6);
    for(int i=0;i<8;i++)cout<<_stack[i]<<" ";
    return 0;
}