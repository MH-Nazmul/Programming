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
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int INF = 1e15;
vector<vector<pair<int, int>>> graph(N);
int n, e;
vector<int> dis(N, INF), vis(N, 0);
void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dis[start] = 0;
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        for (auto child : graph[node])
        {
            int to_dis = child.first;
            int to_node = child.second;
            if (vis[to_node] == 1)
                continue;
            if (dis[to_node] >= to_dis + dis[node])
            {
                dis[to_node] = to_dis + dis[node];
                pq.push({dis[to_node], to_node});
            }
        }
    }
}
void solve(void)
{
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].pb({w, v});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
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