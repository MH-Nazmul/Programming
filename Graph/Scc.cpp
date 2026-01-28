// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define nl cout << "\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define int long long
const int N = 2e5 + 10;
const int M = 1e9 + 7;
int disc[N], low[N], timer = 0;
bool inStack[N];
stack<int> st;
vector<bool> vis(N);
int mn_cost = 0, ways = 1;
vector<vector<int>> g;
vector<int> cost(N);
void dfs(int u)
{
    disc[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = true;

    for (int v : g[u])
    {
        if (!disc[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v])
        {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u])
    {
        int mn = LLONG_MAX, cnt = 0;
        while (true)
        {
            int v = st.top();
            st.pop();
            inStack[v] = false;
            if (mn > cost[v])
            {
                mn = cost[v];
                cnt = 1;
            }
            else if (mn == cost[v])
                cnt++;
            if (v == u)
                break;
        }
        mn_cost += mn;
        ways = (ways * cnt) % M;
    }
}

void solve(void)
{
    int n, m, u, v;
    cin >> n;
    g.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!disc[i])
            dfs(i);
    }
    cout << mn_cost << " " << ways << "\n";
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