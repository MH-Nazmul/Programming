// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long double PI = 3.14159265358979323846;
#define int long long int
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
vector<bool> vis(N);
map<pair<int, int>, bool> repeated;
vector<pair<int, int>> bridges;
vector<int> tin(N), low(N);
int timer;
void dfs(int node, int par, vector<int> graph[])
{
    vis[node] = true;
    tin[node] = low[node] = ++timer;
    for (auto child : graph[node])
    {
        if (child == par)
            continue;
        if (!vis[child])
        {
            dfs(child, node, graph);
            low[node] = min(low[node], low[child]);
            if (low[child] > tin[node])
            {
                if (repeated[{node, child}] == false)
                {
                    bridges.push_back({node, child});
                    repeated[{node, child}] = true;
                }
            }
        }
        else
        {
            low[node] = min(low[node], tin[child]);
        }
    }
    return;
}
void MH(void)
{
    timer = 0;
    bridges.clear();
    int n, e;
    cin >> n >> e;
    fill(vis.begin(), vis.begin() + n + 1, false);
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
    sort(all(bridges));
    for (auto it : bridges)
        cout << it.first << " " << it.second << "\n";
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
