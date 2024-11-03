// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
const int N = 2e5 + 10;
bool vis[N];
vector<int> graph[N];
// undirected graph rooted at 1 DFS Traversing
void dfs(int vertex)
{
    vis[vertex] = true;
    cout << vertex << " ";
    for (auto child : graph[vertex])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
}
void solve(void)
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].pb(v2);
        graph[v2].pb(v1);
    }
    dfs(1);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}