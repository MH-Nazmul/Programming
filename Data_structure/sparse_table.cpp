// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long double PI = 3.14159265358979323846;
#define int long long int
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
vector<int> v(N);

// sparse start   -- 0 based --
vector<vector<int>> sp;
vector<int> lg(N);
void sparse(int n, vector<int> &v)
{
    // build log values
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    sp.assign(n, vector<int>(lg[n] + 1));
    for (int i = 0; i < n; i++)
    {
        sp[i][0] = v[i];
    }
    for (int j = 1; j <= lg[n]; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int sp_qr(int l, int r)
{
    l--, r--; // converting to zero base
    int range = r - l + 1;
    int j = lg[range];
    return min(sp[l][j], sp[r - (1 << j) + 1][j]);
}
// sp end
void MH(void)
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sparse(n, v);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << sp_qr(l, r) << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout << fixed << showpoint << setprecision(20);
    int t = 1, Test;
    // cin >> t;
    for (Test = 1; Test <= t; Test++)
    {
        // cout << "Case " << Test << ": ";
        MH();
    }
    return 0;
}
