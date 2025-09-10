// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long double PI = 3.14159265358979323846;
#define int long long int
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

// euler start --
// paste euler start to end and call euler(root , graph) &
// just call lca(u,v) to get lca of u,v

vector<int> depth, nodes, IndexOfNode(N);
int d = 0, id = 0;
void dfs(int vertex, int par, vector<int> *graph)
{
    depth.push_back(d);
    nodes.push_back(vertex);
    IndexOfNode[vertex] = nodes.size() - 1;
    for (auto child : graph[vertex])
    {
        if (child == par)
            continue;
        d++;
        dfs(child, vertex, graph);
        d--;
        depth.push_back(d);
        nodes.push_back(vertex);
        IndexOfNode[vertex] = nodes.size() - 1;
    }
}

// sparse start   -- 0 based --
vector<vector<int>> sp;
vector<int> lg(N);
void sparse(int n)
{
    // build log values
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    sp.assign(n, vector<int>(lg[n] + 1));
    for (int i = 0; i < n; i++)
    {
        sp[i][0] = i;
    }
    for (int j = 1; j <= lg[n]; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            int left = sp[i][j - 1];
            int right = sp[i + (1 << (j - 1))][j - 1];
            sp[i][j] = (depth[left] <= depth[right]) ? left : right;
        }
    }
}

int sp_qr(int l, int r)
{

    int range = r - l + 1;
    int j = lg[range];
    int left = sp[l][j];
    int right = sp[r - (1 << j) + 1][j];
    return (depth[left] <= depth[right]) ? left : right;
}
// sp end
int lca(int u, int v)
{
    int left = IndexOfNode[u];
    int right = IndexOfNode[v];
    if (left > right)
        swap(left, right);
    int idx = sp_qr(left, right);
    return nodes[idx];
}

void euler(int root, vector<int> *graph)
{
    // vector must be declare like: vector<int>graph[n+1];
    dfs(1, -1, graph);
    sparse(nodes.size());
}

// euler end
void MH(void)
{
    int n, q;
    cin >> n >> q;
    vector<int> graph[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    euler(1, graph);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
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
