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
int sz;
vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> sorted;
    int l = 0, r = 0;
    while (l < left.size() && r < right.size())
    {

        if (left[l] < right[r])
        {
            sorted.push_back(left[l]);
            l++;
        }
        else
        {
            sorted.push_back(right[r]);
            r++;
        }
    }
    while (l < left.size())
    {
        sorted.push_back(left[l]);
        l++;
    }
    while (r < right.size())
    {
        sorted.push_back(right[r]);
        r++;
    }
    return sorted;
}

vector<int> merge_sort(vector<int> v)
{
    if (v.size() == 1)
        return v;
    vector<int> left, right;
    for (int i = 0; i < v.size(); i++)
    {
        if (i < v.size() / 2)
            left.push_back(v[i]);
        else
            right.push_back(v[i]);
    }
    left = merge_sort(left);
    right = merge_sort(right);
    return merge(left, right);
}
void solve(void)
{
    cin >> sz;
    vector<int> v(sz), sorted_array(sz);
    cin(v, sz);
    sorted_array = merge_sort(v);
    for (int i = 0; i < sz; i++)
    {
        cout << sorted_array[i] << " ";
    }
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