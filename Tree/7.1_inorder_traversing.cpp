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
class Tree
{
public:
    int root;
    Tree *left;
    Tree *right;
    Tree(int n)
    {
        root = n;
        left = nullptr;
        right = nullptr;
    }
};
void preorder_tra(Tree *tree)
{

    Tree *tmp = tree;
    if (tmp == nullptr)
        return;
    cout << tmp->root << " ";
    preorder_tra(tmp->left);
    preorder_tra(tmp->right);
}
void solve(void)
{
    Tree *tree = nullptr;
    tree = new Tree(2);
    tree->left = new Tree(3);
    tree->right = new Tree(4);
    tree->left->left = new Tree(5);
    tree->left->right = new Tree(6);
    tree->right->left = new Tree(5);
    tree->right->right = new Tree(6);
    preorder_tra(tree);
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