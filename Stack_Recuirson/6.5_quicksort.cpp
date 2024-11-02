#include <bits/stdc++.h>
using namespace std;
int _quick(vector<int> &v, int lo, int hi)
{
    int pivort = v[lo], sval = lo;
    while (lo <= hi)
    {
        while (v[lo] <= pivort)
            lo++;
        while (v[hi] > pivort)
            hi--;
        if (hi > lo)
            swap(v[lo], v[hi]);
    }
    // if (hi == v.size())
    //     hi--;
    swap(v[sval], v[hi]);
    return hi;
}
void _quicksort(vector<int> &v, int n)
{
    stack<pair<int, int>> st;
    st.push({0, n - 1});
    while (!st.empty())
    {
        int lo = st.top().first;
        int hi = st.top().second;
        st.pop();
        int mid = _quick(v, lo, hi);
        // cout<<mid;
        if (mid > lo + 1)
            st.push({0, mid - 1});
        if (n - 1 > mid + 1)
            st.push({mid + 1, n - 1});
    }
    return;
}
int main(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    _quicksort(v, n);
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    return 0;
}