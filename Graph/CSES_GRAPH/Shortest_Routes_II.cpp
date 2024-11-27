// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define nl cout << "\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define int long long
const int INF = 1e18;

void solve(void)
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> p(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < m; i++)
    {
        int u, v, e;
        cin >> u >> v >> e;

        p[u][v] = min(p[u][v], e);
        p[v][u] = min(p[v][u], e);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[i][k] < INF && p[k][j] < INF)
                {
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
                }
            }
        }
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;

        if (p[u][v] == INF)
            cout << -1 << "\n";
        else
            cout << p[u][v] << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
