#include<bits/stdc++.h>
using namespace std;
long long _fact(int n)
{
    if(n<=1)return 1;
    return n*=_fact(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<_fact(n);
    return 0; 
}