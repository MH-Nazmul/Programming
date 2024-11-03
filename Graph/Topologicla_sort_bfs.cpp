#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int V, vector<vector<int>> &adj)
{
    vector<int> indegree(V, 0);
    vector<int> topo;

    // Calculate indegree of each vertex
    for (int u = 0; u < V; u++)
    {
        for (int v : adj[u])
        {
            indegree[v]++;
        }
    }

    // Queue to store vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Process vertices in topological order
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    return topo;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> topo = topologicalSort(V, adj);

    if (topo.size() != V)
    {
        cout << "The graph is not a DAG, topological sort not possible." << endl;
    }
    else
    {
        cout << "Topological Sort (using Kahn's Algorithm): ";
        for (int u : topo)
        {
            cout << u << " ";
        }
        cout << endl;
    }

    return 0;
}
