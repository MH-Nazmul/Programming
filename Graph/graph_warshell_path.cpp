// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define nl cout << "\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
using ll = long long;
const int N = 2e5 + 10;
const int M = 1e9 + 7;

void solve(void)
{
    int n;
    cin >> n;
    int arr[n+1][n+1];
    for (int i = 0; i < n; i++)
    {
            int v, e;
            cin >> v >> e;
            arr[v][e] = 1;
    }
    int p[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j]==1)
                p[i][j] = 1;
            else
                p[i][j] = 0;
        }
    }
  
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                p[i][j]=(p[i][j] || (p[i][k] && p[k][j]));
            }
        }
    }

     for(int i = 1;i <= n;i++)
       {
        for(int j = 1;j <= n;j++)
           {
            cout<<p[i][j]<<" ";
           }
        cout<<endl; 
       }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}