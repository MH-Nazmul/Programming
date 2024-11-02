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
class DisjointSet
{
    vector<int> par, rank;

public:
    DisjointSet(int n)
    {
        par.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
        }
    }
    int find_parent(int node)
    {
        if (node == par[node])
            return node;
        else
            return par[node] = find_parent(par[node]);
    }
    void union_by_rank(int u, int v)
    {
        int ult_u = find_parent(u);
        int ult_v = find_parent(v);
        if (ult_u == ult_v)
            return;
        else if (rank[ult_u] < rank[ult_v])
        {
            par[ult_u] = ult_v;
        }
        else if (rank[ult_u] > rank[ult_v])
        {
            par[ult_v] = ult_u;
        }
        else
        {
            par[ult_u] = ult_v;
            rank[ult_v]++;
        }
    }
};

void solve(void)
{
    DisjointSet s(8);
    s.union_by_rank(1, 2);
    s.union_by_rank(3, 2);
    s.union_by_rank(3, 4);
    s.union_by_rank(4, 5);
    s.union_by_rank(4, 6);
    s.union_by_rank(7, 8);
    if (s.find_parent(1) == s.find_parent(7))
        cout << "same";
    else
        cout << "not same";
    nl;
    s.union_by_rank(6, 7);
    if (s.find_parent(1) == s.find_parent(7))
        cout << "same";
    else
        cout << "not same";
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