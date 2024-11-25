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

void build_hash(string s, vector<int> &table, vector<int> &pw, int p, int mod)
{
    int n = s.size();
    table[0] = s[0] - 'a' + 1;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = (pw[i - 1] * p) % mod;
        table[i] = (table[i - 1] * p + (s[i] - 'a' + 1)) % mod;
    }
}

int get_substring_hash(int l, int r, const vector<int> &table, const vector<int> &pw, int mod)
{
    int hash_value = table[r];
    if (l > 0)
    {
        hash_value = (hash_value - (table[l - 1] * pw[r - l + 1] % mod) + mod) % mod;
    }
    return hash_value;
}

void solve(void)
{
    int p = 31, sz;
    cin >> sz;
    string s, rs;
    cin >> s;
    rs = s;
    reverse(all(rs));
    vector<int> f_hash_table(sz), r_hash_table(sz), pw(sz);
    build_hash(s, f_hash_table, pw, p, M);
    build_hash(rs, r_hash_table, pw, p, M);

    // substring range input
    int l, r;
    cin >> l >> r;
    int f_sub = get_substring_hash(l, r, f_hash_table, pw, M);

    cout << (f_sub);
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
