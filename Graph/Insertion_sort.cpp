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

void solve(void)
{
    cout << "Input the size of your unsorted array:";
    int sz, j;
    cin >> sz;
    vector<int> v(sz);
    cin(v, sz);
    for (int i = 1; i < sz; i++)
    {
        j = i;
        while (j > 0 and v[j] < v[j - 1])
        {
            swap(v[j], v[j - 1]);
            j--;
        }
    }
    for (int i = 0; i < sz; i++)
        cout << v[i] << " ";
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