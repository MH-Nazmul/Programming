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

vector<bool> vis(N, false);
vector<int> parent(N);
void bfs(int start, int end, vector<vector<int>> &graph)
{
    queue<int> pq;
    pq.push(start);
    while (!pq.empty())
    {
        int point = pq.front();
        pq.pop();
        vis[point] = true;
        if (point == end)
        {
            vector<int> path;
            while (point != start)
            {
                path.push_back(point);
                point = parent[point];
            }
            path.push_back(start);
            cout << path.size() << "\n";
            reverse(all(path));
            for (auto it : path)
                cout << it << " ";
            return;
        }
        for (auto child : graph[point])
        {
            if (vis[child])
                continue;
            else
            {
                vis[child] = true;
                pq.push(child);
                parent[child] = point;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
void solve(void)
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n + 1, vector<int>());
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    bfs(1, n, graph);
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