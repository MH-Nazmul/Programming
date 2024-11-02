#include<bits/stdc++.h>
using namespace std;
void _pop(int _stack[],int &top,int mx)
{
    if(top==-1){cout<<"underflow";return;}
     _stack[top]=0;
    top--;
    return;
}
int main()
{
    int _stack[8]={1,2,3,4,5,0,0,0},top=4;
    for(int i=0;i<8;i++)cout<<_stack[i]<<" ";
    cout<<endl;
    _pop(_stack,top,8);
    _pop(_stack,top,8);
    for(int i=0;i<8;i++)cout<<_stack[i]<<" ";
    return 0;
}