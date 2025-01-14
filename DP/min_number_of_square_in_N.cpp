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
int dp[N];
int minsquare(int n)
{
    if (n <= 3)
        return n;
    if (dp[n] != M)
        return dp[n];
    for (int i = 1; i * i <= n; i++)
    {
        dp[n] = min(dp[n], minsquare(n - i * i) + 1);
    }
    return dp[n];
}
void solve(void)
{
    int n;
    cin >> n;
    cout << "To build " << n << " only";
    cout << minsquare(n) << " number of squares are needed." << endl;
}

signed main()
{
    for (int i = 0; i < N; i++)
        dp[i] = M;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}