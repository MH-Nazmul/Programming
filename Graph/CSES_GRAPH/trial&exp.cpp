#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10; // Maximum number of nodes
vector<int> graph[N];
vector<bool> visited(N, false);
vector<int> parent(N, -1); // To keep track of the parent of each node
int start = -1, _end = -1;

bool dfs(int node, int par)
{
    visited[node] = true;
    for (int child : graph[node])
    {
        if (child == par)
            continue;
        if (visited[child])
        {
            start = child;
            _end = node;
            return true;
        }
        parent[child] = node;
        if (dfs(child, node))
            return true;
    }
    return false;
}

void printCycle(int start, int _end)
{
    vector<int> cycle;
    cycle.push_back(start);
    int cur = _end;
    while (cur != start)
    {
        cycle.push_back(cur);
        cur = parent[cur];
    }
    cycle.push_back(start); // Complete the cycle
    reverse(cycle.begin(), cycle.end());

    cout << "Cycle found: ";
    for (int node : cycle)
    {
        cout << node << " ";
    }
    cout << endl;
}

int main()
{
    int n, e;
    cin >> n >> e; // Number of nodes and edges
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Since the graph is undirected
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
                break;
        }
    }

    if (start == -1)
    {
        cout << "No cycle found in the graph.\n";
    }
    else
    {
        printCycle(start, _end);
    }

    return 0;
}
