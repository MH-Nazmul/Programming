// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int INF = 1e18;
int NODE;
vector<int> dis(N, INF);
void dijkstra(int source, vector<pair<int, int>> graph[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> vis(N, false);
    dis[source] = 0;
    pq.push({0, source});
    int node, distance;
    while (!pq.empty())
    {
        node = pq.top().second;
        distance = pq.top().first;
        pq.pop();
        // if (distance > dis[node])
        //     continue;
        for (auto it : graph[node])
        {
            int to_node = it.second;
            int to_distance = it.first;
            if (dis[to_node] > dis[node] + to_distance)
            {
                dis[to_node] = dis[node] + to_distance;
                pq.push({dis[to_node], to_node});
            }
        }
    }
    // lets print the shortest path from source to all node;
    for (int i = 1; i <= NODE; i++)
    {
        cout << "distance from node :" << source << " to node :" << i << " is :" << dis[i] << "\n";
    }
}

void solve(void)
{
    int edge;
    cin >> NODE >> edge;
    vector<pair<int, int>> graph[N];
    for (int i = 0; i < edge; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1].pb({w, v2});
        graph[v2].pb({w, v1});
    }
    int source;
    cin >> source;
    dijkstra(source, graph);
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