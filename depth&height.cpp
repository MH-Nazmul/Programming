/*                                     MH_Nazmul
                                  Let it be as simple
                                                                             */
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
using ll = long long;
const int N = 1e5 + 10;
vector<int> graph[N];
int depth[N];
int height[N];

void dfs(int vertex, int par)
{
    for (int child : graph[vertex])
    {
        if (child == par)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

void solve(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1, 0);
    cout << "printing depth\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Depth of vertex : " << i << " is " << depth[i] << "\n";
    }
    cout << "printing height" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Height of vertex : " << i << " is " << height[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}