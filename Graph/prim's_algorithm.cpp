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

void prims_cal(vector<vector<pair<int, int>>> &graph)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> vis(N, false);
    pair<int, int> zero = {0, 1};
    pq.push(zero);
    int node, weight, total_cost = 0;
    while (!pq.empty())
    {
        node = pq.top().second;
        weight = pq.top().first;
       
        pq.pop();
        if (vis[node] == true)
            continue;

        vis[node] = true;
        total_cost += weight;
        for (auto it : graph[node])
        {
            if (vis[it.first])
                continue;
            pq.push({it.second, it.first});
        }
       
    }
    cout << total_cost;
}
void solve(void)
{
    int node, edge;
    cin >> node >> edge;
    vector<vector<pair<int, int>>> graph(node + 5);
    while (edge--)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1].pb({v2, w});
        graph[v2].pb({v1, w});
    }
    prims_cal(graph);
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