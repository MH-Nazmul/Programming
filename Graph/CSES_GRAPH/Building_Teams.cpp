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
vector<vector<int>> graph(N);
vector<int> team(N, -1);

bool colors(int source, int par, int color)
{
    if (team[source] != -1)
    {
        return team[source] == color;
    }

    team[source] = color;
    bool biparted = true;

    for (auto child : graph[source])
    {
        biparted &= colors(child, source, (color ^ 1));
        if (!biparted)
            return false;
    }

    return biparted;
}

void solve(void)
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i <= n; i++)
    {
        graph[i].clear();
        team[i] = -1;
    }

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (team[i] == -1)
        {
            if (!colors(i, -1, 1))
            {
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << team[i] + 1 << " ";
    }
    nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
