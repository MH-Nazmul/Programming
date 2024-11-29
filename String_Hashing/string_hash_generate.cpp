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

int build_hash(string s, vector<int> &pw, int p, int mod)
{
    int n = s.size();
    int hash = 0;
    pw[0] = 1;
    for (int i = 0; i < n; i++)
    {
        pw[i] = (pw[i - 1] * p) % mod;
        hash = (hash + ((s[i] - 'a' + 1) * pw[i]) % mod) % mod;
    }
    return hash;
}

void solve(void)
{
    int p = 31, sz;
    cin >> sz;
    string s;
    cin >> s;
    vector<int> pw(sz);
    int hash = build_hash(s, pw, p, M);

    cout << hash;
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