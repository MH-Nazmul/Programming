#include <bits/stdc++.h>
using namespace std;
struct info
{
    int n;
    char src, aux, dest;
    info(int num, char source, char auxilary, char destination)
    {
        n = num;
        src = source;
        aux = auxilary;
        dest = destination;
    }
};
void _hanoi(int _n, char src, char aux, char dest)
{
    stack<info> st;
    info tp(_n, src, aux, dest);
    st.push(tp);
    while (!st.empty())
    {
        info tmp = st.top();
        st.pop();
        if (tmp.n == 1)
        {
            cout << tmp.src << " to " << tmp.dest << "\n";
        }
        else
        {
            info third(tmp.n - 1, tmp.aux, tmp.src, tmp.dest);
            st.push(third);

            info two(1, tmp.src, tmp.aux, tmp.dest);
            st.push(two);

            info one(tmp.n - 1, tmp.src, tmp.dest, tmp.aux);
            st.push(one);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    _hanoi(n, 'A', 'B', 'C');
    return 0;
}