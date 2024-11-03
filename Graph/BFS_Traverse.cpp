// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
const int N = 2e5 + 10;

vector<int> graph[N];
bool vis[N];
// undirected graph rooted at 1 BFS Traversing
void bfs(int vertex)
{
    queue<int> q;
    q.push(vertex);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (vis[node])
            continue;
        cout << node << " ";
        vis[node] = true;

        for (auto child : graph[node])
        {
            if (vis[child])
                continue;
            q.push(child);
        }
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
    bfs(1);
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