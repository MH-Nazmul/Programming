#include<bits/stdc++.h>
using namespace std;
void _hanoi(int n,char src,char aux,char dest)
{
    if(n==1)
    {
        cout<<src<<" to "<<dest<<"\n";
    }
    else
    {
        _hanoi(n-1,src,dest,aux);
         cout<<src<<" to "<<dest<<"\n";
        _hanoi(n-1,aux,src,dest); 
    }
}
int main()
{
   int n;
   cin>>n;
   _hanoi(n,'A','B','C');
    return 0;
}