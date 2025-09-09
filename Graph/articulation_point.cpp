// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long double PI = 3.14159265358979323846;
#define int long long int
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
vector<int> tin(N), low(N);
set<int> points;
vector<bool> vis(N);
int timer;
void dfs(int node, int par, vector<int> graph[])
{
    vis[node] = true;
    tin[node] = low[node] = ++timer;
    int children = 0;
    for (auto child : graph[node])
    {
        if (child == par)
            continue;
        if (!vis[child])
        {
            children++;
            dfs(child, node, graph);
            low[node] = min(low[node], low[child]);
            if (par != -1 and low[child] >= tin[node])
            {
                points.insert(node);
            }
        }
        else
        {
            low[node] = min(low[node], tin[child]);
        }
    }
    if (par == -1 and children > 1)
    {
        points.insert(node);
    }
    return;
}
void MH(void)
{
    int n, e;
    cin >> n >> e;
    timer = 0;
    fill(vis.begin(), vis.begin() + n + 1, false);
    points.clear();

    vector<int> graph[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, -1, graph);
    }

    for (auto it : points)
        cout << it << " ";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout << fixed << showpoint << setprecision(20);
    int t = 1, Test;
    // cin >> t;
    for (Test = 1; Test <= t; Test++)
    {
        // cout << "Case " << Test << ": ";
        MH();
    }
    return 0;
}
