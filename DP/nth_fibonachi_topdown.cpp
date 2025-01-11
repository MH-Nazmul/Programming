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
map<int, int> table;

int nth_fibo(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    if (table[n] != 0)
        return table[n];
    table[n] = nth_fibo(n - 2) + nth_fibo(n - 1);
    return table[n];
}
void solve(void)
{
    int n;
    cin >> n;
    cout << nth_fibo(n);
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