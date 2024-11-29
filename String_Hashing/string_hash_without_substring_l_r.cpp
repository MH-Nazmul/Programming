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

vector<int> f_hash_table(N), r_hash_table(N), pw(N), pwi(N);

inline int bigMod(int a, int b, int M)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1LL)
            res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1LL;
    }
    return res;
}
inline int fermats_inverse(int a, int M) { return bigMod(a, M - 2, M); }

void build_hash_table(string s, vector<int> &table, vector<int> &pw, int p, int mod)
{
    int n = s.size();
    table[0] = s[0] - 'a' + 1;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = (pw[i - 1] * p) % mod;
        pwi[i] = fermats_inverse(pw[i], M);
        table[i] = (table[i - 1] + (pw[i] * (s[i] - 'a' + 1)) % mod) % mod;
        // cout << "table["<<i<<"=" << table[i] << " ";
    }
}

// int get_substring_hash(int l, int r, const vector<int> table, const vector<int> pwi, int mod)
// {
//     int hash_value = table[r];
//     // cout << "hash_val= " << table[r] << " ";
//     if (l > 0)
//     {
//         hash_value = (((hash_value - table[l - 1] + mod) % mod) * pwi[r - l + 1]) % mod;
//     }
//     return hash_value;
// }
int get_string_hash_without_substring(int sub_l, int sub_r, int string_size, vector<int> &hash_table)
{
    int mod = M;
    int left_part = 0;
    if (sub_l > 0)
        left_part = hash_table[sub_l - 1];
    int right_part = (((hash_table[string_size - 1] - hash_table[sub_r] + mod) % mod) * pwi[sub_r - sub_l + 1]) % mod;
    return (left_part + right_part) % mod;
}

void solve(void)
{
    int p = 31, sz;
    cin >> sz;
    string s, rs;
    cin >> s;
    rs = s;
    reverse(all(rs));
    build_hash_table(s, f_hash_table, pw, p, M);
    build_hash_table(rs, r_hash_table, pw, p, M);
    int l, r;
    cin >> l >> r;
    cout << "forward hash without substring L to R :" << get_string_hash_without_substring(l, r, sz, f_hash_table) << "\n";

    cout << "Reverse hash without substring L to R :" << get_string_hash_without_substring(sz - r - 1, sz - l - 1, sz, r_hash_table);
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