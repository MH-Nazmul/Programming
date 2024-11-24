// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define nl cout << "\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define f(a, b, c) for (int a = b; a < c; a++)
#define cin(vec, n) \
    f(i, 0, n) { cin >> vec[i]; }
#define int long long
const int N = 2e5 + 10;
const int M = 1e9 + 7;
vector<vector<int>> graph(N);
vector<bool> vis(N, false);
vector<int> parent(N, -1), path;
void dfs(int vertex, int par = -1)
{
    vis[vertex] = true;
    for (int child : graph[vertex])
    {
        if (child == par)
            continue;
        if (vis[child])
        {
            int tmp = vertex;
            path.push_back(child);
            while (tmp != child)
            {
                path.pb(tmp);
                tmp = parent[tmp];
            }
            path.pb(child);
            return;
        }
        vis[child] = true;
        parent[child] = vertex;
        dfs(child, vertex);
        if (!path.empty())
            return;
    }
}
void solve(void)
{
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    for (int i = 1; i <= node; i++)
    {
        if (path.size() >= 1)
        {
            cout << path.size() << "\n";
            for (auto it : path)
                cout << it << " ";
            return;
        }

        if (!vis[i])
            dfs(i);
    }
    cout << "IMPOSSIBLE";
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