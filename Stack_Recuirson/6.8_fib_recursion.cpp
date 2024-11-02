#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int _fib(int n)
{
    if(n==0){return 0;}
    if(n==1){return 1;}
    return (_fib(n-1)+_fib(n-2)); 
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    cout<<_fib(i)<<" ";
    return 0;
}